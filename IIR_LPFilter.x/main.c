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
#include <stdio.h>
#include <stdlib.h>

#define INTERRUPT_PROTECT(x)                \
    {                                       \
        char saved_ipl;                     \
        SET_AND_SAVE_CPU_IPL(saved_ipl, 7); \
        x;                                  \
        RESTORE_CPU_IPL(saved_ipl);         \
    }                                       \
    (void)0;

// Function Declarations
void uart_init(void);
void clk_init(void);
void uart_send_string(volatile uint8_t* _string);
void timer1_init(void);
void adc_init(void);
void dac_init(void);

// Variable Declarations
volatile static uint16_t timerCount;
volatile static uint16_t adcBuffer;
volatile static bool filterUpdateFlag;
volatile static char sbuffer[256];
volatile static uint8_t* buffer;

// Initialize IIR Filter
IIR_LPFilter myFilter;
IIR_BiQuad_DF1_Filter myfilt;

int main(void)
{

    // Initialized clock
    clk_init();

    // Initialize IIR filter coeffecients
//    IIR_LPFilterInit(&myFilter, 0.01547, -0.9691);

    IIR_BiQuad_DF1_Filter_Init(&myfilt, -1.6630, 0.7199, 0.0140, 0.0279, 0.0140);

    // Configure LED Pin
    gpio_config_pin_output(GPIOD, 15);
    gpio_config_pin_output(GPIOC, 8);

    // Configure Pin for UART using PPS
//     pps_pin_config_input(U1RX, GPIOC, 15);
    // pps_pin_config_output(U1TX, GPIOC, 14);

    // Configure pins for ADC
    gpio_config_analog_pin(GPIOC, 7);
    gpio_config_pin_input(GPIOC, 7);

    // Configure ADC
    adc_init();

    // Configure DAC
    dac_init();

    // Configure Timer1
    timer1_init();

    // Configure USART
    // uart_init();

    while (1) {

        if (filterUpdateFlag) {
//            IIR_LPFilterUpdate(&myFilter, adcBuffer);
            IIR_BiQuad_DF1_Filter_Update(&myfilt, adcBuffer);
            filterUpdateFlag = 0;
        }
    }

    return 0;
}

void __attribute__((interrupt, auto_psv)) _ADCAN15Interrupt(void)
{
    IFS6bits.ADCAN15IF = 0;
    adcBuffer = ADCBUF15;
}

void __attribute__((interrupt, auto_psv)) _U1TXInterrupt(void)
{
    IFS0bits.U1TXIF = 0;

    if (U1STAHbits.UTXBE) {
        if (*buffer) {
            U1TXREG = *buffer;
            buffer++;
        }
    }
}

void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void)
{
    IFS0bits.U1RXIF = 0;
    volatile uint8_t dummyRead = U1RXREG;
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0;
    filterUpdateFlag = 1;

    ADCON3Lbits.SWCTRG = 1;
    DAC1DATH = myfilt.yn;

    if (timerCount >= 1000) {
        gpio_pin_toggle(GPIOD, 15);
        timerCount = 0;
    }

    timerCount++;
}

void dac_init(void)
{

    // Fvco/2 as clk source
    DACCTRL1L |= 1u << 6u;

    // analog voltage is connected to the dacout1 pin
    DAC1CONL |= 1u << 9u;

    // enables dac1 module
    DAC1CONL |= 1u << 15u;

    // enables all dac modules
    DACCTRL1L |= 1u << 15u;
}

void adc_init(void)
{
    // Configure the common ADC clock
    ADCON3Hbits.CLKSEL = 0; // Fp

    // Configure the ADC reference source
    ADCON3Lbits.REFSEL = 0;
    ADCON2Lbits.SHRADCS = 0;

    // Configure Shared ADC Core Resolution
    ADCON1Hbits.SHRRES = 3u; // 12 bit resolution

    // Configure the output if integer or fractional
    ADCON1Hbits.FORM = 0; // integer

    // Unsigned output format
    ADMOD0Hbits.SIGN15 = 0;

    // Shared ADC core sample time selection
    ADCON2Hbits.SHRSAMC = 0;

    // Clear flags and Enable Interrupts
    _ADCAN15IF = 0;
    _ADCAN15IE = 1u;
    ADIELbits.IE15 = 1u;

    // Set ADON to enable the module and warmtime
    ADCON1Lbits.ADON = 1u;
    ADCON5Hbits.WARMTIME = 0;

    // Turn on module power
    ADCON5Lbits.SHRPWR = 1u;
    while (!(ADCON5Lbits.SHRRDY))
        ;
    ADCON3Hbits.SHREN = 1u;

    ADTRIG3Hbits.TRGSRC15 = 0x01u;
}

void uart_init(void)
{

    // Select clock source
    U1MODEH |= 0u << 9u;

    // Select Fractional Divider
    U1MODEH |= (1u << 11u);

    // Calculate BRG from Baud Rate BRG = Fp / Baud Rate
    U1BRG = 781;

    // Configure data width and parity
    U1MODE |= 0u << 0u;

    // Configure polarity, stop bit duration, and flow control
    U1MODEH |= 0u << 4u;
    U1MODEH |= (0 << _U1MODEH_URXINV_POSITION);
    U1MODEH |= 0u << 0u;

    // Configure Interrupt watermark
    U1STAH |= 0u << 8u;
    U1STAH |= 0u << 12u;

    // Clear Flag
    IFS0bits.U1TXIF = 0;

    // Configure Interrupt Priority Level
    IPC3 |= (3u << _IPC3_U1TXIP_POSITION);
    IPC3 |= (3u << _IPC3_U1TXIP_POSITION);

    // Enable TX Interrupt
    IEC0 |= (1u << _IEC0_U1TXIE_POSITION);
    IEC0 |= (1u << _IEC0_U1RXIE_POSITION);

    // Set UART Enable
    U1MODEbits.UARTEN = 1u;

    // Set Transmit and Receiver Enable
    U1MODEbits.UTXEN = 1u;
    U1MODEbits.URXEN = 1u;
}

void clk_init(void)
{

    // Configure PLL prescaler, both PLL postscalers, and PLL feedback divider
    CLKDIVbits.PLLPRE = 1; // N1=1
    PLLFBDbits.PLLFBDIV = 180; // M = 180
    PLLDIVbits.POST1DIV = 4; // N2=4
    PLLDIVbits.POST2DIV = 1; // N3=1

    // Initiate Clock Switch to FRC with PLL (NOSC=0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);

    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0)
        ;
}

void uart_send_string(volatile uint8_t* _string)
{
    //    U1MODEbits.UTXEN = 1;
    buffer = _string;
    U1TXREG = *buffer;
    buffer++;
}

void timer1_init(void)
{
    // TMR 0;
    TMR1 = 0x00;
    // Tick Interrupt of 2000 Hz
    PR1 = 0xAF;
    T1CON = 0x8030;

    // Clear T1 flag
    IFS0 &= ~(1u << 1u);
    // Priority
    IPC0 |= 3u << 4u;
    // Enable
    IEC0 |= 1u << 1u;
}
