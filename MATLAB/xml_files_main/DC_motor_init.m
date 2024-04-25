clear,clc;

upper_sat_voltage = 30; % V
lower_sat_voltage = 0; % V

upper_torque_limit = 4; % Nm

T_disturbance = 1; % Nm

L = 0.90e-3; % H
R = 0.43; % Ohm
Kt = 0.08; % Nm/A  -- torque
Ke = 0.08; % V/(rad/s)  -- back electromotive force
J_rotor = 2118.45e-7; % kg.m2
B_motor = 1.9099e-4; % Nms/rad

open_system("my_DC_motor_control_position.slx")
%open_system("my_DC_motor_control_torque.slx")