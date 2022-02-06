#ifndef _IIR_LPFILTER_
#define _IIR_LPFILTER_

#include <stdint.h>

typedef struct IIR_LPFilter {

  float alpha;
  float beta;
  volatile float yn;
  volatile float xn;

} IIR_LPFilter;

typedef struct IIR_LPFilter_Q15 {
    
    int* ptrAlpha;
    int* ptrBeta;
    volatile int* ptrControlHistory;
    volatile int* ptrErrorHistory;

    uint16_t    preShift ;              // Normalization from ADC-resolution to Q15 (R/W)
    int16_t     postShift ;             // Normalization bit-shift from Q15 to PWM register resolution (R/W)
    int16_t     postScaler ;            // Controller output post-scaler  (R/W)
    uint16_t    minOutput ;             // Minimum output value used for clamping (R/W)
    uint16_t    maxOutput ;             // Maximum output value used for clamping (R/W)
    
} IIR_LPFilter_Q15;

typedef struct C3P3Z_CONTROL_LOOP_COEFFICIENTS_s
{
    volatile int ACoefficients[2]; // A-Coefficients
    volatile int BCoefficients[1]; // B-Coefficients
} __attribute__((packed)) C3P3Z_CONTROL_LOOP_COEFFICIENTS_t;

typedef struct C3P3Z_CONTROL_LOOP_HISTORIES_s
{
    volatile int ControlHistory[2];  // Control History Array
    volatile int ErrorHistory[1]; // Error History Array
} __attribute__((packed)) C3P3Z_CONTROL_LOOP_HISTORIES_t;

void IIR_LPFilter_Init(IIR_LPFilter *filt, float alpha, float beta);
float IIR_LPFilter_Update(IIR_LPFilter *filt, uint16_t input);

//void IIR_LPFilter_Q15_Init(IIR_LPFilter_Q15 *filt, int* _alpha, int* _beta);
extern int IIR_LPFilter_Q15_Update(IIR_LPFilter *filt, uint16_t input);

#endif _IIR_LPFILTER_