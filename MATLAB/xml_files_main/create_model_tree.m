clear, clc

%% general const
Ts = 0.001;  % sampling time in seconds
degToRad_const = pi/180;
mmToM_const = 1e-3;
motor_torque_limit = 200;  % N.m
motor_force_limit = 200;  % N

%% create model tree
[my_scara, my_scara_info] = importrobot("my_scara_root");

%% load robot data
my_scara_DataFile;

%% waypoints and timepoints (joint space)
wp_joint = [0 90 120 150 120 -150;
            0 -90 -30 0 90 160;
            0 50 100 280 200 50];
wp_joint(1:2,:) = wp_joint(1:2,:) .* degToRad_const;
wp_joint(3,:) = wp_joint(3,:) .* mmToM_const;
segTimePoint_joint = [0.5 1 1 1 1;
                    0.5 1 1 1 1;
                    0.5 1 1 1 1];  % for trapezoidal trajectory

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

L = 0.90e-3; % H
R = 0.43; % Ohm
Kt = 0.08; % Nm/A
Ke = 0.08; % V/(rad/s)
J_rotor = 2118.45e-7; % kg.m2
B_motor = 1.9099e-4; % Nms/rad
