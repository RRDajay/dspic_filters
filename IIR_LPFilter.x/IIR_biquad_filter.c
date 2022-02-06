#include "IIR_biquad_filter.h"
#include "stdint.h"

void IIR_BiQuad_DF1_Filter_Init(IIR_BiQuad_DF1_Filter *filt, double _a1,
                                double _a2, double _b0, double _b1,
                                double _b2) {

  filt->xn = 0;
  filt->xnp = 0;
  filt->yn = 0;
  filt->ynp = 0;

  filt->a1 = _a1;
  filt->a2 = _a2;
  filt->b0 = _b0;
  filt->b1 = _b1;
  filt->b2 = _b2;
  
}

double IIR_BiQuad_DF1_Filter_Update(IIR_BiQuad_DF1_Filter *filt,
                                    uint16_t input) {

  double output = filt->b0 * input + filt->b1 * filt->xn +
                  filt->b2 * filt->xnp - filt->a1 * filt->yn -
                  filt->a2 * filt->ynp;

  filt->xnp = filt->xn;
  filt->xn = input;

  filt->ynp = filt->yn;
  filt->yn = output;

  return output;
}
