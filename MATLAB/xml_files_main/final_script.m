clear, clc

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

%% create model tree
[my_scara, my_scara_info] = importrobot("my_scara_root", 'DataFormat','row');

%% load robot data
my_scara_DataFile;

%% waypoints and timepoints (task space)

%------------------------------------------------
wp = [809 500 500 500 500 500 300 300 300 300 500;  %x
      955 955 676 677 955 955 955 955 676 955 955;  %y  -- vertical
      0 300 300 300 300 500 500 300  300 300 300];  %z

segTimePoint = [0.5 0.5 1 0.5 1 1 1 0.5 0.5 1];  % time to travel each seg

isStraight = [0 1 1 1 1 1 1 1 1 1];
%------------------------------------------------
%% generate traperzoidal trajectory (task space)
pts_lst = [];
tSamples = [];

for i = 1:length(isStraight)
    if isStraight(i)
        [pts_lst_straight, tSamples_straight] = doStraightInterp(wp(:, i), wp(:, i + 1), segTimePoint(i));
        pts_lst = [pts_lst pts_lst_straight];
        if ~isempty(tSamples)
            tSamples_straight = tSamples_straight + tSamples(end);
        end
        
        tSamples = [tSamples tSamples_straight];
    else
        radius = 500;
        [pts_lst_circular, center, isSuccess, tSamples_circular] = doCircularInterp(wp(:,1),wp(:,2),true,radius,segTimePoint(i));
        if ~isSuccess
            disp("[ERROR] Radius is less than the distance between points");
            quit;
        end
        pts_lst = [pts_lst pts_lst_circular'];
        if ~isempty(tSamples)
            tSamples_circular = tSamples_circular + tSamples(end);
        end
        tSamples = [tSamples tSamples_circular'];
    end
end
%% inverse kinematics
% verify traj using Inverse Kinematics
solverParams = struct('EnforceJointLimits',false);
ik = inverseKinematics('RigidBodyTree',my_scara, 'SolverAlgorithm', 'LevenbergMarquardt', 'SolverParameters', solverParams);
weights = [0 0 0 1 1 1];
initialguess = homeConfiguration(my_scara);
endEffector = 'Body4';
configSol_arr = zeros(3, length(pts_lst));

for i = 1:length(pts_lst)
    point = pts_lst(:,i).*(1e-03);  % convert mm to m

    [configSol, solInfo] = ik(endEffector, trvec2tform(point'), weights, initialguess);

    initialguess = configSol;
%     j1 = configSol(1).JointPosition/pi*180;
%     j2 = configSol(2).JointPosition/pi*180;
%     j3 = configSol(3).JointPosition*1e03;
    j1 = configSol(1)/pi*180;
    j2 = configSol(2)/pi*180;
    j3 = configSol(3)*1e03;

    % condition checking
    if (abs(j1) > 150) || (abs(j2) > 160) || (j3 < 0) || (j3 > 280)
        disp(abs(j1) > 150);
        disp(abs(j2) > 160);
        disp(j3 < 0);
        disp(j3 > 280);
        disp("[ERROR] Point NOT in work space");
        disp(point);
        break;
    end
%     configSol_arr(:,i) = [configSol(1).JointPosition;configSol(2).JointPosition;configSol(3).JointPosition];
    configSol_arr(:,i) = [configSol(1);configSol(2);configSol(3)];
end 

q_draw = pts_lst';
q_draw(:,2) = q_draw(:,2) - offset_draw;
q_draw = unique(q_draw, "rows", "stable");
anchor_pts = unique(wp',"rows");
anchor_pts = [anchor_pts; center];
anchor_pts(:,2) = anchor_pts(:,2) - offset_draw;

dataJoint_load = [tSamples', configSol_arr'];

open_system("my_scara_control_kinematics.slx");
