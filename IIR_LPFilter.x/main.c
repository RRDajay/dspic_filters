/*
 * File:   main.c
 * Author: ryanr
 *
 * Created on September 30, 2021, 12:21 AM
 */

#include "IIR_LPFilter.h"
#include "IIR_biquad_filter.h"
#include "config.h"
#include "gpio.h"
#include "pps.h"
#include <math.h>
#include <p33CH512MP506.h>
#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */
void uart_init(void);
void clk_init(void);
void uart_send_string(volatile uint8_t *_string);
void timer1_init(void);
void adc_init(void);
void dac_init(void);

/* Variable Declarations */
volatile static uint16_t timerCount;
volatile static uint16_t adcBuffer;
volatile static bool filterUpdateFlag;
volatile static char sbuffer[256];
volatile static uint8_t *buffer;

/* A/B-Coefficients */
volatile struct C3P3Z_CONTROL_LOOP_COEFFICIENTS_s
    __attribute__((space(xmemory), near))
    c3p3z_coefficients;

/* Control/Error Histories */
volatile struct C3P3Z_CONTROL_LOOP_HISTORIES_s
    __attribute__((space(ymemory), far))
    c3p3z_histories; 

//#define __IIR__
#define __IIR_Q15__
//#define __BIQUAD__
/* Initialize IIR Filter */

#if defined(__IIR_Q15__)
IIR_LPFilter_Q15 myFilter_Q15;
#endif
#if defined(__IIR__)
IIR_LPFilter myFilter;
#endif
#if defined(__BIQUAD__)
IIR_BiQuad_DF1_Filter myfilt;
#endif
#if defined(__IIR_Q15__)

void filter_init() {
    
  c3p3z_coefficients.ACoefficients[0] = 0x117f;
  c3p3z_coefficients.ACoefficients[1] = 0x117f;
  c3p3z_coefficients.BCoefficients[0] = 0x5CFE;
  
  myFilter_Q15.ptrAlpha = &c3p3z_coefficients.ACoefficients;
  myFilter_Q15.ptrBeta = &c3p3z_coefficients.BCoefficients;
  myFilter_Q15.ptrControlHistory = &c3p3z_histories.ControlHistory;
  myFilter_Q15.ptrErrorHistory = &c3p3z_histories.ErrorHistory;
  
  myFilter_Q15.minOutput = 0;
  myFilter_Q15.maxOutput = 0x0FFF;
  
}
#endif

int main(void) {

  /* Initialize clock */
  clk_init();

  /* Initialize IIR filter coeffecients */
#if defined(__IIR_Q15__)
//  IIR_LPFilter_Q15_Init(&myFilter_Q15, 0x117F, 0xA302);
  filter_init();
#endif
#if defined(__IIR__)
  IIR_LPFilter_Init(&myFilter, 0.1367, 0.7265);
#endif
#if defined(__BIQUAD__)
  IIR_BiQuad_DF1_Filter_Init(&myfilt, -1.6630, 0.7199, 0.0140, 0.0279, 0.0140);
#endif

  /* Configure LED Pin */
  gpio_config_pin_output(GPIOD, 15);
  gpio_config_pin_output(GPIOC, 8);

  /* Configure Pin for UART using PPS */
  // pps_pin_config_input(U1RX, GPIOC, 15);
  // pps_pin_config_output(U1TX, GPIOC, 14);
  
  /* Configure pins for ADC */
  gpio_config_analog_pin(GPIOC, 7); 
  gpio_config_pin_input(GPIOC, 7);

  adc_init();    
  dac_init();    
  timer1_init(); 
  // uart_init(); 
  
  filterUpdateFlag = 1;
  while (1) {
    if (filterUpdateFlag) {
      filterUpdateFlag = 0;
      
#if defined(__IIR_Q15__)
//      IIR_LPFilter_Q15_Update(&myFilter_Q15, adcBuffer);
#endif
      
#if defined(__IIR__)
      IIR_LPFilter_Update(&myFilter, adcBuffer);
#endif
      
#if defined(__BIQUAD__)
      IIR_BiQuad_DF1_Filter_Update(&myfilt, adcBuffer);
#endif
      
    }
  }

  return 0;
}

void __attribute__((interrupt, auto_psv)) _ADCAN15Interrupt(void)
{
  IFS6bits.ADCAN15IF = 0;
  adcBuffer = ADCBUF15;
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    
#if defined(__IIR__)
    
  IFS0bits.T1IF = 0;
  ADCON3Lbits.SWCTRG = 1;
  filterUpdateFlag = 1;
  DAC1DATH = myFilter.yn;

#endif

#if defined(__IIR_Q15__)
  filterUpdateFlag = 0;
    
  char saved_ipl;
  SET_AND_SAVE_CPU_IPL(saved_ipl, 7);
  
  IFS0bits.T1IF = 0;
  ADCON3Lbits.SWCTRG = 1;
  DAC1DATH = (uint16_t)(*myFilter_Q15.ptrErrorHistory);
  IIR_LPFilter_Q15_Update(&myFilter_Q15, adcBuffer);
  if (i < 2048) adcSample[i++] = adcBuffer;
  if (j < 2048) filterOutput[j++] = *myFilter_Q15.ptrErrorHistory;
  
  RESTORE_CPU_IPL(saved_ipl);
  
#endif

  if (timerCount >= 1000) {
    gpio_pin_toggle(GPIOD, 15);
    timerCount = 0;
  }
  timerCount++;
  
}

void dac_init(void) {
    
    /* Fvco/2 as clk source */
    DACCTRL1L |= 1u << 6u;
    
    /* Analog voltage is connected to the dacout1 pin */
    DAC1CONL |= 1u << 9u;
    
    /* Enable DAC Module */
    DAC1CONL |= 1u << 15u;  
    DACCTRL1L |= 1u << 15u; 
    
}

void adc_init(void) {

    /* Configure the common ADC clock, Fp */
    ADCON3Hbits.CLKSEL = 0; 

    /* Configure the ADC reference source */
    ADCON3Lbits.REFSEL = 0;
    ADCON2Lbits.SHRADCS = 0;
    ADCON1Hbits.SHRRES = 3u; 

    /* ADC Data Format */
    ADCON1Hbits.FORM = 0; // integer
//    ADCON1Hbits.FORM = 1; // fractional

    /* Signed output format */
    ADMOD0Hbits.SIGN15 = 0;
//    ADMOD0Hbits.SIGN15 = 1;

    /* Shared ADC core sample time selection */
    ADCON2Hbits.SHRSAMC = 0;

  /* Clear flags and Enable Interrupts */
    _ADCAN15IF = 0;
    _ADCAN15IE = 1u;
    ADIELbits.IE15 = 1u;

  /* Set ADON to enable the module and warmtime */
    ADCON1Lbits.ADON = 1u;
    ADCON5Hbits.WARMTIME = 0;

  /* Turn on module power */
    ADCON5Lbits.SHRPWR = 1u;
    while (!(ADCON5Lbits.SHRRDY));
    ADCON3Hbits.SHREN = 1u;

    ADTRIG3Hbits.TRGSRC15 = 0x01u;
}

void timer1_init(void) {
  /* TMR 0; */
  TMR1 = 0x00;
  /* Tick Interrupt of 2000 Hz */
  PR1 = 0xaf;
  T1CON = 0x8030;

  /* Clear T1 flag; Set Priority and Enable Interrupt */
  IFS0 &= ~(1u << 1u);
  IPC0 |= 3u << 4u;
  IEC0 |= 1u << 1u;
}

void clk_init(void) {

  /* Configure PLL prescaler, both PLL postscalers, and PLL feedback divider */
  CLKDIVbits.PLLPRE = 1;     // N1=1
  PLLFBDbits.PLLFBDIV = 180; // M = 180
  PLLDIVbits.POST1DIV = 4;   // N2=4
  PLLDIVbits.POST2DIV = 1;   // N3=1

  /* Initiate Clock Switch to FRC with PLL (NOSC=0b001) */
  __builtin_write_OSCCONH(0x01);
  __builtin_write_OSCCONL(OSCCON | 0x01);

  /* Wait for Clock switch to occur */
  while (OSCCONbits.OSWEN != 0);
}

void __attribute__((interrupt, auto_psv)) _U1TXInterrupt(void) {
  IFS0bits.U1TXIF = 0;

  if (U1STAHbits.UTXBE) {
    if (*buffer) {
      U1TXREG = *buffer;
      buffer++;
    }
  }
}

void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void) {
  IFS0bits.U1RXIF = 0;
}

void uart_init(void) {

  U1MODEH |= 0u << 9u;    // Select clock source
  U1MODEH |= (1u << 11u); // Select Fractional Divider
  U1BRG = 781;            // Calculate BRG from Baud Rate BRG = Fp / Baud Rate
  U1MODE |= 0u << 0u;     // Configure data width and parity

  // Configure polarity, stop bit duration, and flow control
  U1MODEH |= 0u << 4u;
  U1MODEH |= (0 << _U1MODEH_URXINV_POSITION);
  U1MODEH |= 0u << 0u;

  // Configure Interrupt watermark
  U1STAH |= 0u << 8u;
  U1STAH |= 0u << 12u;

  IFS0bits.U1TXIF = 0; // Clear Flag

  // Configure Interrupt Priority Level
  IPC3 |= (3u << _IPC3_U1TXIP_POSITION);
  IPC3 |= (3u << _IPC3_U1TXIP_POSITION);

  // Enable TX Interrupt
  IEC0 |= (1u << _IEC0_U1TXIE_POSITION);
  IEC0 |= (1u << _IEC0_U1RXIE_POSITION);

  U1MODEbits.UARTEN = 1u; // Set UART Enable

  // Set Transmit and Receiver Enable
  U1MODEbits.UTXEN = 1u;
  U1MODEbits.URXEN = 1u;
}

void uart_send_string(volatile uint8_t *_string) {
  //    U1MODEbits.UTXEN = 1;
  buffer = _string;
  U1TXREG = *buffer;
  buffer++;
}

