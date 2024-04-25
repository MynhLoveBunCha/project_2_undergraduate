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
[my_scara, my_scara_info] = importrobot("my_scara_root");

%% load robot data
my_scara_DataFile;

%% trajectory tracking
% waypoints and timepoints (task space)

%------------------------------------------------
wp = [810 500;  %x
      955 955;  %y  -- vertical
       0  300]; %z
radius = 500;
isNegInterp = false;
segTimePoint = 1;  % time to travel each seg
%------------------------------------------------
[pts_lst, center, isSuccess, tSamples] = doCircularInterp(wp(:,1),wp(:,2),isNegInterp,radius,segTimePoint);

count = length(tSamples);
if isSuccess
    % verify traj using Inverse Kinematics
    solverParams = struct('EnforceJointLimits',false);
    ik = inverseKinematics('RigidBodyTree',my_scara, 'SolverAlgorithm', 'LevenbergMarquardt', 'SolverParameters', solverParams);
    weights = [0 0 0 1 1 1];
    initialguess = homeConfiguration(my_scara);
    endEffector = 'Body4';
    configSol_arr = zeros(3, count);
    
    for i = 1:count
        point = pts_lst(i,:).*(1e-03);  % convert mm to m
    
        [configSol, solInfo] = ik(endEffector, trvec2tform(point), weights, initialguess);
    
        initialguess = configSol;
        j1 = configSol(1).JointPosition/pi*180;
        j2 = configSol(2).JointPosition/pi*180;
        j3 = configSol(3).JointPosition*1e03;
    
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
        configSol_arr(:,i) = [configSol(1).JointPosition;configSol(2).JointPosition;configSol(3).JointPosition];
    end 
    
    q_draw = pts_lst;
    q_draw(:,2) = q_draw(:,2) - offset_draw;
    
    anchor_pts = [wp';center];
    anchor_pts(:,2) = anchor_pts(:,2) - offset_draw;
    
    dataJoint_load = [tSamples, configSol_arr'];
    open_system("my_scara_control_kinematics.slx");
end