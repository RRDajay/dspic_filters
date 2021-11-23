clc; clear;

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 

% calculate pre-warped analog frequency

s = tf('s');
% wd <= ws/2

fc = 100;                    % cut off frequency
Ts = 1/2000;                 % desired sampling time
w_d = 2*pi*(fc);             % digital frequency
w_a = 2/Ts * tan(w_d*Ts/2);  % rad/s

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 

% Transfer function with pre-warped analog frequency
H_s = 1 / (1 + s/w_a); 

% Apply the z-transform to the transfer function and sketch the bode plot
H_z = c2d(H_s, Ts, 'tustin')
bode(H_z, H_s)
