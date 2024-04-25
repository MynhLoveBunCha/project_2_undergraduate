clear,clc;
%% general const
Ts = 0.001;  % sampling time in seconds
degToRad_const = pi/180;
mmToM_const = 1e-3;
motor_torque_limit = 200;  % N.m
motor_force_limit = 200;  % N
offset_draw = 515;

%% DC motor const
upper_sat_voltage = 30; % V
lower_sat_voltage = 0; % V

upper_torque_limit = 4; % Nm

gear_ratio_j1 = 10/1;
gear_ratio_j2 = 10/1;
ball_screw_ratio = 2*pi*(2/1)/(10e-2);  % torque to force

n1 = 1/80;
n2 = 1/80;
n3 = 10/1;
p3 = 0.015; %m

L = 5.4e-3; % H
R = 1.45; % Ohm
Kt = 0.957; % Nm/A
Ke = 0.957; % V/(rad/s)
J_rotor = 125e-4; % kg.m2
B_motor = 6.78e-4; % Nms/rad
%% load robot data
my_scara_DataFile;