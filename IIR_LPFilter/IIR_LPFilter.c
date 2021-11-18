#include "IIR_LPFilter.h"

void IIR_LPFilterInit(IIR_LPFilter *filt, double alpha, double beta) {
  filt->alpha = alpha;
  filt->beta = beta;
  filt->xn = 0.0;
  filt->yn = 0.0;
}

double IIR_LPFilterUpdate(IIR_LPFilter *filt, uint16_t input) {

  filt->yn =
      filt->alpha * input + filt->alpha * filt->xn - filt->beta * filt->yn;

  filt->xn = input;

  return filt->yn;
}