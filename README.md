# Summary

DSP filters implemented on the dsPIC33. This repo contains fixed-point assembly implementation of IIR Low Pass filters. The assembly version of the code uses dsp instructions to use the DSP engine of the dsPIC33.

Matlab file to get the coefficients of the filter are also included in the repository. 

Filters examples in the repo:
1. single order IIR low pass filters
2. second order IIR low pass filters

# Disclaimer

This repo is a personal project of mine to properly understand the design process of digital filters. 

# To Do

1. Reorganize the code structure to make it more readable by separating the periphal initialization to its own .h and .c files. 

2. I might do other filters and a fixed point PID implementation in the future.

