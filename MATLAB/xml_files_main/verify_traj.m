[q,qd,qdd,tSamples,pp] = trapveltraj(wp,1000,"EndTime",segTimePoint);
plot(tSamples, q)
xlabel('t')
ylabel('Positions')