#ifndef _PPS_H_
#define _PPS_H_

#include "gpio.h"

// Remappable Pins
#define RP32 32UL
#define RP33 33UL
#define RP34 34UL
#define RP35 35UL
#define RP36 36UL
#define RP37 37UL
#define RP38 38UL
#define RP39 39UL
#define RP40 40UL
#define RP41 41UL
#define RP42 42UL
#define RP43 43UL
#define RP44 44UL
#define RP45 45UL
#define RP46 46UL
#define RP47 47UL

#define RP48 48UL
#define RP49 49UL
#define RP50 50UL
#define RP51 51UL
#define RP52 52UL
#define RP53 53UL
#define RP54 54UL
#define RP55 55UL
#define RP56 56UL
#define RP57 57UL
#define RP58 58UL
#define RP59 59UL
#define RP60 60UL
#define RP61 61UL
#define RP62 62UL
#define RP63 63UL

#define RP64 64UL
#define RP65 65UL
#define RP66 66UL
#define RP67 67UL
#define RP68 68UL
#define RP69 69UL
#define RP70 70UL
#define RP71 71UL

#define SOnRPIPS 168UL
#define SOffRPIPS 169UL

#define SVRPV0 170UL
#define SVRPV1 171UL
#define SVRPV2 172UL
#define SVRPV3 173UL
#define SVRPV4 174UL
#define SVRPV5 175UL

#define MVRPV0 176UL
#define MVRPV1 177UL
#define MVRPV2 178UL
#define MVRPV3 179UL
#define MVRPV4 180UL
#define MVRPV5 181UL

// Input Selection for Remappable Pins
#define INT1 1UL
#define INT2 2UL
#define INT3 3UL
#define T1CK 4UL
#define TCKI1 5UL
#define ICM1 6UL
#define TCKI2 7UL
#define ICM2 8UL
#define TCKI3 9UL
#define ICM3 10UL
#define TCKI4 11UL
#define ICM4 12UL
#define TCKI5 13UL
#define ICM5 14UL
#define TCKI6 15UL
#define ICM6 16UL
#define TCKI7 17UL
#define ICM7 18UL
#define TCKI8 19UL
#define ICM8 20UL
#define OCFA 21UL
#define OCFB 22UL
#define PCI8 23UL
#define PCI9 24UL
#define PCI10 25UL
#define PCI11 26UL
#define QEIA1 27UL
#define QEIB1 28UL
#define QEINDX1 29UL
#define QEIHOM1 30UL
#define U1RX 31UL
#define U1DSR 32UL
#define U2RX 33UL
#define U2DSR 34UL
#define SDI1 35UL
#define SCK1IN 36UL
#define SS1I 37UL
#define REFOI 38UL
#define SDI2 39UL
#define SCK2IN 40UL
#define SS2I 41UL
#define U1CTS 42UL
#define CAN1RX 43UL
#define CAN2RX 44UL
#define U2CTS 45UL
#define PCI17 46UL
#define PCI18 47UL
#define PCI12 48UL
#define PCI13 49UL
#define PCI14 50UL
#define PCI15 51UL
#define PCI16 52UL
#define SENT1 53UL
#define SENT2 54UL
#define CLCINA 55UL
#define CLCINB 56UL
#define CLCINC 57UL
#define CLCIND 58UL
#define ADCTRG 59UL

// Output Selection for Remappable pins
#define U1TX 1UL
#define U1RTS 2UL
#define U2TX 3UL
#define U2RTS 4UL
#define SDO1 5UL
#define SCK1 6UL
#define SS1O 7UL
#define SDO2 8UL
#define SCK2 9UL
#define SS2O 10UL
#define REFO 14UL
#define OCM1 15UL
#define OCM2 16UL
#define OCM3 17UL
#define OCM4 18UL
#define OCM5 19UL
#define OCM6 20UL
#define CAN1TX 21UL
#define CAN2TX 22UL
#define CMP1 23UL
#define PWM4H 34UL
#define PWM4L 35UL
#define PWMEA 36UL
#define PWMEB 37UL
#define QEICMP 38UL
#define CLC1OUT 40UL
#define CLC2OUT 41UL
#define OCM7 42UL
#define OCM8 43UL
#define PWMEC 44UL
#define PWMED 45UL
#define PTGTRG24 46UL
#define PTGTRG25 47UL
#define SENT1OUT 48UL
#define SENT2OUT 49UL
#define CLC3OUT 50UL
#define CLC4OUT 51UL
#define U1DTR 52UL
#define U2DTR 53UL

// Function Prototypes
void pps_pin_config_output(uint16_t desiredPeripheral, GPIO_Typedef *port,
                           uint16_t pinNum);
void pps_pin_config_input(uint16_t desiredPeripheral, GPIO_Typedef *port,
                          uint16_t pinNum);
uint16_t pps_pin_map(GPIO_Typedef *port, uint16_t pinNum);

#endif