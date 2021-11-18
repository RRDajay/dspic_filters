#ifndef _IIR_LPFILTER_
#define _IIR_LPFILTER_

#include <stdint.h>

typedef struct IIR_LPFilter {

  double alpha;
  double beta;
  volatile double yn;
  volatile double xn;

} IIR_LPFilter;

void IIR_LPFilterInit(IIR_LPFilter *filt, double alpha, double beta);
double IIR_LPFilterUpdate(IIR_LPFilter *filt, uint16_t input);

#endif _IIR_LPFILTER_