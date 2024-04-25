clear, clc

%% general const
Ts = 0.001;  % sampling time in seconds
degToRad_const = pi/180;
mmToM_const = 1e-3;
motor_torque_limit = 200;  % N.m
motor_force_limit = 200;  % N
offset_draw = 515;

%% create model tree
[my_scara, my_scara_info] = importrobot("my_scara_root", DataFormat="row");

%% load robot data
my_scara_DataFile;

%% waypoints and timepoints (task space)

%------------------------------------------------
wp = [810 500 500 500 500 300 300 300 300 500;  %x
      955 955 676 955 955 955 955 676 955 955;  %y  -- vertical
      0 300 300 300 500 500 300  300 300 300];  %z

segTimePoint = [0.5 0.5 0.5 1 1 1 0.5 0.5 1];  % time to travel each seg
%------------------------------------------------


segTimePoint = [segTimePoint;
                segTimePoint;
                segTimePoint];
%% generate traperzoidal trajectory (task space)
[q,qd,qdd,tSamples,pp] = trapveltraj(wp,1000,"EndTime",segTimePoint);

%% inverse kinematics
% verify traj using Inverse Kinematics
solverParams = struct('EnforceJointLimits',false);
ik = inverseKinematics('RigidBodyTree',my_scara, 'SolverAlgorithm', 'LevenbergMarquardt', 'SolverParameters', solverParams);
weights = [0 0 0 1 1 1];
initialguess = homeConfiguration(my_scara);
endEffector = 'Body4';

%jacob = geometricJacobian(my_scara,)  TODO: find jacobian

configSol_arr = zeros(length(q), 3);
mass_matrix = zeros(length(q)*3, 3);
grav_torques = zeros(length(q), 3);

for i = 1:length(q)
    point = q(:,i).*(1e-03);  % convert mm to m

    [configSol, solInfo] = ik(endEffector, trvec2tform(point'), weights, initialguess);

    initialguess = configSol;
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
    configSol_arr(i,:) = configSol;
    mass_matrix((3*i-2):(3*i),:) = massMatrix(my_scara, configSol);
    grav_torques(i,:) = gravityTorque(my_scara, configSol);

end 

%% find joint space vel
jVelArray = [0 0 0; diff(configSol_arr,1,1)./diff([tSamples',tSamples',tSamples'],1,1)];
seg_time_new = diff([tSamples',tSamples',tSamples'],1,1);
q_draw = q';
q_draw(:,2) = q_draw(:,2) - offset_draw;
anchor_pts = unique(wp',"rows");
anchor_pts(:,2) = anchor_pts(:,2) - offset_draw;

dataJoint_load = [tSamples', configSol_arr];

%open_system("my_scara_control_kinematics.slx");
