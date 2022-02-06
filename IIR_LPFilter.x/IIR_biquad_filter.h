#ifndef _IIR_BIQUAD_H_
#define _IIR_BIQUAD_H_

typedef struct IIR_BiQuad_DF1_Filter {

  double a1, a2;
  double b0, b1, b2;

  volatile double xn, xnp;
  volatile double yn, ynp;

} IIR_BiQuad_DF1_Filter;


void IIR_DF1_LPBiquadInit();
void IIR_DF1_LPBiquadUpdate();

#endif