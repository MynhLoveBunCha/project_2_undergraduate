function [pts_lst, center, isSuccess, tSamples] = doCircularInterp(pt_from,pt_to,isNegInterp,radius,segTimePoint)

isSuccess = true;

syms x y;

p1 = [pt_from(3), pt_from(1)];
p2 = [pt_to(3), pt_to(1)];
r = radius;

midPts = [((p1(1)+p2(1))/2), ((p1(2)+p2(2))/2)];
vec_n = [(p1(1)-p2(1)), (p1(2)-p2(2))];

min_radius = sqrt((p1(1)-midPts(1))^2 + (p1(2)-midPts(2))^2);

if r <= min_radius
    isSuccess = false;
    disp("[ERROR] Radius is smaller than minimum radius. Try increase radius!")
    pts_lst = [];
    center = [];
else
    % solve for center points
    eqns = [vec_n(1)*(x-midPts(1))+vec_n(2)*(y-midPts(2))==0, (x-p1(1))^2+(y-p1(2))^2==r^2];
    S = solve(eqns,[x y]);
    solutions = [double(S.x) double(S.y)];
    
    center1 = solutions(1,:);
    center2 = solutions(2,:);
    
    % check cross product
    vec_from = [p1 - center1, 0];
    vec_to = [p2 - center1, 0];
    crossProd = cross(vec_from, vec_to);
    isCross1Neg = crossProd(:,3) < 0;

    if xor(isCross1Neg, isNegInterp)
        center = [center2(2), pt_from(2), center2(1)];
        x_c = center2(1);
        y_c = center2(2);
        theta1 = cart2pol(p1(1)-x_c,p1(2)-y_c);
        theta2 = cart2pol(p2(1)-x_c,p2(2)-y_c);
        tSamples = linspace(0, segTimePoint, 100)'; % sampling time
        th = (tSamples/tSamples(end)) * (theta2-theta1) + theta1;
%         if theta1 <= theta2
%             th = (tSamples/tSamples(end)) * (theta2-theta1) + theta1;
%         else
%             th = (tSamples/tSamples(end)) * (theta1-theta2) + theta2;
%         end
        
        xunit = r * cos(th) + x_c;
        yunit = r * sin(th) + y_c;
        pts_lst = [yunit, repmat(pt_from(2),length(tSamples),1), xunit];

    else
        center = [center1(2), pt_from(2), center1(1)];
        x_c = center1(1);
        y_c = center1(2);
        theta1 = cart2pol(p1(1)-x_c,p1(2)-y_c);
        theta2 = cart2pol(p2(1)-x_c,p2(2)-y_c);
        tSamples = linspace(0, segTimePoint, 1000)'; % sampling time
        th = (tSamples/tSamples(end)) * (theta2-theta1) + theta1;
%         if theta1 <= theta2
%             th = (tSamples/tSamples(end)) * (theta2-theta1) + theta1;
%         else
%             th = (tSamples/tSamples(end)) * (theta1-theta2) + theta2;
%         end
        
        xunit = r * cos(th) + x_c;
        yunit = r * sin(th) + y_c;
        pts_lst = [yunit, repmat(pt_from(2),length(tSamples),1), xunit];
    end
end



end