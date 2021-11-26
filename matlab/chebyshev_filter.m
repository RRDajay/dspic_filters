clc;clear;
% Specify filter order
n = 4; 

% Specify passband ripple
Rp = 10;

% Specify passband edge frequency and sampling rate
Fs = 2000;
Wc = 100;
Wp = Wc * 2 * 1 / Fs;

% [b,a] = cheby1(n, Rp, Wp);
[b,a] = cheby1(2, 0.15, 0.05)
freqz(b,a)

% dataIn = randn(1000,1);
% dataOut = filter(b,a,dataIn);
% 
% t = 0:1:999;
% plot(t,dataIn)
% hold on
% plot(t,dataOut)