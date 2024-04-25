%% Configuring slTuner

% tuner object
controlInputs = {'controller 1', 'controller 2', 'controller 3'};
measurements = 'ROBOT/q';  % joint angle measurement
tuner = slTuner("my_scara_control_PID", controlInputs);

% define plant inputs
addPoint(tuner, controlInputs);

% define plant outputs
addPoint(tuner, measurements);

% define reference signals
refSigs = {
    'my_scara_control_PID/Signal Builder/J1 CF';
    'my_scara_control_PID/Signal Builder/J2 CF';
    'my_scara_control_PID/Signal Builder/J3 CF'};

addPoint(tuner, refSigs);

%% Tuning
for i=1:1
    tuningOptions = looptuneOptions('RandomStart', 200, 'UseParallel', true);
    goalFunc = TuningGoal.StepTracking(refSigs, measurements, 0.5);
    newWeights = looptune(tuner, controlInputs, measurements, goalFunc, tuningOptions);
    tuner = newWeights;
end
%% Update PID blocks
writeBlockValue(newWeights);
