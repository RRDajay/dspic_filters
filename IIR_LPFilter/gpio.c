#include "gpio.h"

void gpio_config_pin_output (GPIO_Typedef *port,  uint16_t pinNum) {
    // Clear pin at pin position
    port->TRIS &= ~(1 << pinNum);
}

void gpio_config_pin_input(GPIO_Typedef *port, uint16_t pinNum) {
    // Set bit at pin position
    port->TRIS |= (1 << pinNum);
}

void gpio_pin_toggle(GPIO_Typedef *port, uint16_t pinNum) {
    // Toggle bit at pin position
    port->LAT ^= (1 << pinNum);
}

void gpio_pin_set(GPIO_Typedef *port, uint16_t pinNum) {
    // Set bit at pin position
    port->LAT |= (1 << pinNum);
}

void gpio_pin_reset(GPIO_Typedef *port, uint16_t pinNum) {
    // Clear bit at pin position
    port->LAT &= ~(1 << pinNum);
}

bool gpio_pin_read(GPIO_Typedef *port, uint16_t pinNum) {
    
    // Store port values at temp variable
    uint16_t temp =  port->PORT;
    
    // Bitmask at the desired pin position
    return temp & (1 << pinNum);
}
