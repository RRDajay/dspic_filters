#include "IIR_LPFilter.h"

void IIR_LPFilter_Init(IIR_LPFilter *filt, float alpha, float beta) {
    
  filt->alpha = alpha;
  filt->beta = beta;
  filt->xn = 0.0;
  filt->yn = 0.0;
  
}

float IIR_LPFilter_Update(IIR_LPFilter *filt, uint16_t input) {

  filt->yn = filt->alpha * input + filt->alpha * filt->xn + filt->beta * filt->yn;
  filt->xn = input;
  
  return filt->yn;
  
}