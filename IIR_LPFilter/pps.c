#include "pps.h"

void pps_pin_config_output(uint16_t desiredPeripheral, GPIO_Typedef *port,
                           uint16_t pinNum) {

  // Lock Registers
  __builtin_write_RPCON(0x0000);

  // Set pin as output
  gpio_config_pin_output(port, pinNum);

  if (port == GPIOB) {
    if (pinNum == 0)
      RPOR0 |= (desiredPeripheral << _RPOR0_RP32R_POSITION);
    if (pinNum == 1)
      RPOR0 |= (desiredPeripheral << _RPOR0_RP33R_POSITION);
    if (pinNum == 2)
      RPOR1 |= (desiredPeripheral << _RPOR1_RP34R_POSITION);
    if (pinNum == 3)
      RPOR1 |= (desiredPeripheral << _RPOR1_RP35R_POSITION);
    if (pinNum == 4)
      RPOR2 |= (desiredPeripheral << _RPOR2_RP36R_POSITION);
    if (pinNum == 5)
      RPOR2 |= (desiredPeripheral << _RPOR2_RP37R_POSITION);
    if (pinNum == 6)
      RPOR3 |= (desiredPeripheral << _RPOR3_RP38R_POSITION);
    if (pinNum == 7)
      RPOR3 |= (desiredPeripheral << _RPOR3_RP39R_POSITION);
    if (pinNum == 8)
      RPOR4 |= (desiredPeripheral << _RPOR4_RP40R_POSITION);
    if (pinNum == 9)
      RPOR4 |= (desiredPeripheral << _RPOR4_RP41R_POSITION);
    if (pinNum == 10)
      RPOR5 |= (desiredPeripheral << _RPOR5_RP42R_POSITION);
    if (pinNum == 11)
      RPOR5 |= (desiredPeripheral << _RPOR5_RP43R_POSITION);
    if (pinNum == 12)
      RPOR6 |= (desiredPeripheral << _RPOR6_RP44R_POSITION);
    if (pinNum == 13)
      RPOR6 |= (desiredPeripheral << _RPOR6_RP45R_POSITION);
    if (pinNum == 14)
      RPOR7 |= (desiredPeripheral << _RPOR7_RP46R_POSITION);
    if (pinNum == 15)
      RPOR7 |= (desiredPeripheral << _RPOR7_RP47R_POSITION);
  }

  if (port == GPIOC) {
    if (pinNum == 0)
      RPOR8 |= (desiredPeripheral << _RPOR8_RP48R_POSITION);
    if (pinNum == 1)
      RPOR8 |= (desiredPeripheral << _RPOR8_RP49R_POSITION);
    if (pinNum == 2)
      RPOR9 |= (desiredPeripheral << _RPOR9_RP50R_POSITION);
    if (pinNum == 3)
      RPOR9 |= (desiredPeripheral << _RPOR9_RP51R_POSITION);
    if (pinNum == 4)
      RPOR10 |= (desiredPeripheral << _RPOR10_RP52R_POSITION);
    if (pinNum == 5)
      RPOR10 |= (desiredPeripheral << _RPOR10_RP53R_POSITION);
    if (pinNum == 6)
      RPOR11 |= (desiredPeripheral << _RPOR11_RP54R_POSITION);
    if (pinNum == 7)
      RPOR11 |= (desiredPeripheral << _RPOR11_RP55R_POSITION);
    if (pinNum == 8)
      RPOR12 |= (desiredPeripheral << _RPOR12_RP56R_POSITION);
    if (pinNum == 9)
      RPOR12 |= (desiredPeripheral << _RPOR12_RP57R_POSITION);
    if (pinNum == 10)
      RPOR13 |= (desiredPeripheral << _RPOR13_RP58R_POSITION);
    if (pinNum == 11)
      RPOR13 |= (desiredPeripheral << _RPOR13_RP59R_POSITION);
    if (pinNum == 12)
      RPOR14 |= (desiredPeripheral << _RPOR14_RP60R_POSITION);
    if (pinNum == 13)
      RPOR14 |= (desiredPeripheral << _RPOR14_RP61R_POSITION);
    if (pinNum == 14)
      RPOR15 |= (desiredPeripheral << _RPOR15_RP62R_POSITION);
    if (pinNum == 15)
      RPOR15 |= (desiredPeripheral << _RPOR15_RP63R_POSITION);
  }

  if (port == GPIOD) {
    if (pinNum == 0)
      RPOR16 |= (desiredPeripheral << _RPOR16_RP64R_POSITION);
    if (pinNum == 1)
      RPOR16 |= (desiredPeripheral << _RPOR16_RP65R_POSITION);
    if (pinNum == 2)
      RPOR17 |= (desiredPeripheral << _RPOR17_RP66R_POSITION);
    if (pinNum == 3)
      RPOR17 |= (desiredPeripheral << _RPOR17_RP67R_POSITION);
    if (pinNum == 4)
      RPOR18 |= (desiredPeripheral << _RPOR18_RP68R_POSITION);
    if (pinNum == 5)
      RPOR18 |= (desiredPeripheral << _RPOR18_RP69R_POSITION);
    if (pinNum == 6)
      RPOR19 |= (desiredPeripheral << _RPOR19_RP70R_POSITION);
    if (pinNum == 7)
      RPOR19 |= (desiredPeripheral << _RPOR19_RP71R_POSITION);
  }

  // Unlock Registers
  __builtin_write_RPCON(0x0800);
}

void pps_pin_config_input(uint16_t desiredPeripheral, GPIO_Typedef *port,
                          uint16_t pinNum) {

  // Lock Registers
  __builtin_write_RPCON(0x0000);

  // Configure pin as input
  gpio_config_pin_input(port, pinNum);

  if (desiredPeripheral == INT1)
    RPINR0bits.INT1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == INT2)
    RPINR1bits.INT2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == INT3)
    RPINR1bits.INT3R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == T1CK)
    RPINR2bits.T1CKR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI1)
    RPINR3bits.TCKI1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM1)
    RPINR3bits.ICM1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI2)
    RPINR4bits.TCKI2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM2)
    RPINR4bits.ICM2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI3)
    RPINR5bits.TCKI3R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM3)
    RPINR5bits.ICM3R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI4)
    RPINR6bits.TCKI4R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM4)
    RPINR6bits.ICM4R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI5)
    RPINR7bits.TCKI5R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM5)
    RPINR7bits.ICM5R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI6)
    RPINR8bits.TCKI6R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM6)
    RPINR8bits.ICM6R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI7)
    RPINR9bits.TCKI7R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM7)
    RPINR9bits.ICM7R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == TCKI8)
    RPINR10bits.TCKI8R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ICM8)
    RPINR10bits.ICM8R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == OCFA)
    RPINR11bits.OCFAR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == OCFB)
    RPINR11bits.OCFBR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI8)
    RPINR12bits.PCI8R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI9)
    RPINR12bits.PCI9R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI10)
    RPINR13bits.PCI10R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI11)
    RPINR13bits.PCI11R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == QEIA1)
    RPINR14bits.QEIA1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == QEIB1)
    RPINR14bits.QEIB1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == QEINDX1)
    RPINR15bits.QEINDX1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == QEIHOM1)
    RPINR15bits.QEIHOM1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == U1RX)
    RPINR18bits.U1RXR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == U1DSR)
    RPINR18bits.U1DSRR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == U2RX)
    RPINR19bits.U2RXR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == U2DSR)
    RPINR19bits.U2DSRR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SDI1)
    RPINR20bits.SDI1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SCK1IN)
    RPINR20bits.SCK1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SS1I)
    RPINR21bits.SS1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == REFOI)
    RPINR21bits.REFOIR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SDI2)
    RPINR22bits.SDI2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SCK2IN)
    RPINR22bits.SCK2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SS2I)
    RPINR23bits.SS2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == U1CTS)
    RPINR23bits.U1CTSR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == CAN1RX)
    RPINR26bits.CAN1RXR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == CAN2RX)
    RPINR26bits.CAN2RXR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == U2CTS)
    RPINR30bits.U2CTSR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI17)
    RPINR37bits.PCI17R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI18)
    RPINR38bits.PCI18R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI12)
    RPINR42bits.PCI12R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI13)
    RPINR42bits.PCI13R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI14)
    RPINR43bits.PCI14R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI15)
    RPINR43bits.PCI15R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == PCI16)
    RPINR44bits.PCI16R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SENT1)
    RPINR44bits.SENT1R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == SENT2)
    RPINR45bits.SENT2R = pps_pin_map(port, pinNum);
  if (desiredPeripheral == CLCINA)
    RPINR45bits.CLCINAR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == CLCINB)
    RPINR46bits.CLCINBR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == CLCINC)
    RPINR46bits.CLCINCR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == CLCIND)
    RPINR47bits.CLCINDR = pps_pin_map(port, pinNum);
  if (desiredPeripheral == ADCTRG)
    RPINR47bits.ADCTRGR = pps_pin_map(port, pinNum);

  // Unlock Registers
  __builtin_write_RPCON(0x0800);
}

uint16_t pps_pin_map(GPIO_Typedef *port, uint16_t pinNum) {

  if (port == GPIOB) {
    if (pinNum == 0)
      return RP32;
    if (pinNum == 1)
      return RP33;
    if (pinNum == 2)
      return RP34;
    if (pinNum == 3)
      return RP35;
    if (pinNum == 4)
      return RP36;
    if (pinNum == 5)
      return RP37;
    if (pinNum == 6)
      return RP38;
    if (pinNum == 7)
      return RP39;
    if (pinNum == 8)
      return RP40;
    if (pinNum == 9)
      return RP41;
    if (pinNum == 10)
      return RP42;
    if (pinNum == 11)
      return RP43;
    if (pinNum == 12)
      return RP44;
    if (pinNum == 13)
      return RP45;
    if (pinNum == 14)
      return RP46;
    if (pinNum == 15)
      return RP47;
  }

  if (port == GPIOC) {
    if (pinNum == 0)
      return RP48;
    if (pinNum == 1)
      return RP49;
    if (pinNum == 2)
      return RP50;
    if (pinNum == 3)
      return RP51;
    if (pinNum == 4)
      return RP52;
    if (pinNum == 5)
      return RP53;
    if (pinNum == 6)
      return RP54;
    if (pinNum == 7)
      return RP55;
    if (pinNum == 8)
      return RP56;
    if (pinNum == 9)
      return RP57;
    if (pinNum == 10)
      return RP58;
    if (pinNum == 11)
      return RP59;
    if (pinNum == 12)
      return RP60;
    if (pinNum == 13)
      return RP61;
    if (pinNum == 14)
      return RP62;
    if (pinNum == 15)
      return RP63;
  }

  if (port == GPIOD) {
    if (pinNum == 0)
      return RP64;
    if (pinNum == 1)
      return RP65;
    if (pinNum == 2)
      return RP66;
    if (pinNum == 3)
      return RP67;
    if (pinNum == 4)
      return RP68;
    if (pinNum == 5)
      return RP69;
    if (pinNum == 6)
      return RP70;
    if (pinNum == 7)
      return RP71;
  }

  return 0;
}