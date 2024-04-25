clear,clc,close all
syms x y;

p1 = [1, 2];
p2 = [8, 9];
r = 20;

midPts = [((p1(1)+p2(1))/2), ((p1(2)+p2(2))/2)];
vec_n = [(p1(1)-p2(1)), (p1(2)-p2(2))];

disp(sqrt((p1(1)-midPts(1))^2 + (p1(2)-midPts(2))^2));  % min radius

% solve for center points
eqns = [vec_n(1)*(x-midPts(1))+vec_n(2)*(y-midPts(2))==0, (x-p1(1))^2+(y-p1(2))^2==r^2];
S = solve(eqns,[x y]);
disp(double(S.x));
disp(double(S.y));
solutions = [double(S.x) double(S.y)];

center1 = solutions(1,:);
center2 = solutions(2,:);

my_circle(center1, r, p1, p2);

function h = my_circle(center,r,p1,p2)
hold on
x_c = center(1);
y_c = center(2);
theta1 = cart2pol(p1(1)-x_c,p1(2)-y_c);
theta2 = cart2pol(p2(1)-x_c,p2(2)-y_c);

if theta1 <= theta2
    th = theta1:pi/1000:theta2;
else
    th = theta1:-pi/1000:theta2;
end

xunit = r * cos(th) + x_c;
yunit = r * sin(th) + y_c;


% check cross product
vec_from = [p1 - center, 0];
vec_to = [p2 - center, 0];
crossProd = cross(vec_from, vec_to);
if crossProd(:,3) >= 0
    disp("Positive interpolation");
else
    disp("Negative interpolation");
end

h = plot(xunit, yunit);
plot(x_c,y_c,'*');
plot(p1(1),p1(2),'*');
plot(p2(1),p2(2),'*');
hold off
end