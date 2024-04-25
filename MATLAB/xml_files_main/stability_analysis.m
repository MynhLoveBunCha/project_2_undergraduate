clear,clc, close all;

jl = 431704e-09;
n = 10;
p = 15e-3;

jm = 125e-04;
Bm = 6.78e-04;
Bl = 0.001;
Km = 0.957;
Ke = 0.957;
R = 1.45;
L = 5.4e-03;



jtd = jm+n^2*jl;
Btd = Bm+n^2*Bl;

tau_t = L/R;
tau_c = jtd/Btd;

Ktd = Km/(Km*Ke+R*Btd);
T1 = (tau_t*tau_c*R*Btd)/(Km*Ke+R*Btd);
T2 = ((tau_t+tau_c)*R*Btd)/(Km*Ke+R*Btd);

s = tf('s');
G3 = (Ktd*p/(2*pi))/(T1*s^3+T2*s^2+s);

H = feedback(G3,1);
step(H,5000);

