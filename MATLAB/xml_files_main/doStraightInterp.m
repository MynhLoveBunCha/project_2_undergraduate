function [q,tSamples] = doStraightInterp(pt_from, pt_to, segTimePoint)

wp = [pt_from pt_to];

[q,qd,qdd,tSamples,pp] = trapveltraj(wp,200,"EndTime",segTimePoint);
end