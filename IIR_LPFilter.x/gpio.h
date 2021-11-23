#ifndef _GPIO_H_ 
#define _GPIO_H_

#include <xc.h>
#include "stdint.h"
#include "stdbool.h"

// SFR address for dsPIC33CH
#define GPIOA_BASE  0x0E00UL
#define GPIOB_BASE  0x0E1CUL
#define GPIOC_BASE  0x0E38UL
#define GPIOD_BASE  0x0E54UL
#define GPIOE_BASE  0x0E70UL

typedef struct {
    volatile uint16_t ANSEL;
    volatile uint16_t TRIS;
    volatile uint16_t PORT;
    volatile uint16_t LAT;
    volatile uint16_t ODC;
    volatile uint16_t CNPU;
    volatile uint16_t CNPD;
    volatile uint16_t CNCON;
    volatile uint16_t CNEN0;
    volatile uint16_t CNSTAT;
    volatile uint16_t CNEN1;
    volatile uint16_t CNF;
} GPIO_Typedef;

#define GPIOA ((GPIO_Typedef*)GPIOA_BASE)
#define GPIOB ((GPIO_Typedef*)GPIOB_BASE)
#define GPIOC ((GPIO_Typedef*)GPIOC_BASE) 
#define GPIOD ((GPIO_Typedef*)GPIOD_BASE)
#define GPIOE ((GPIO_Typedef*)GPIOE_BASE)

void gpio_config_pin_output (GPIO_Typedef *port,  uint16_t pinNum);

void gpio_config_pin_input(GPIO_Typedef *port, uint16_t pinNum);

void gpio_config_analog_pin(GPIO_Typedef *port, uint16_t pinNum);

void gpio_pin_toggle(GPIO_Typedef *port, uint16_t pinNum);

void gpio_pin_set(GPIO_Typedef *port, uint16_t pinNum);

void gpio_pin_reset(GPIO_Typedef *port, uint16_t pinNum);

bool gpio_pin_read(GPIO_Typedef *port, uint16_t pinNum);

#endif