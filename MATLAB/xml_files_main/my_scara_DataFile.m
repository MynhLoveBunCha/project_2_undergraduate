% Simscape(TM) Multibody(TM) version: 7.6

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(12).translation = [0.0 0.0 0.0];
smiData.RigidTransform(12).angle = 0.0;
smiData.RigidTransform(12).axis = [0.0 0.0 0.0];
smiData.RigidTransform(12).ID = "";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [350 -103.7003243291656 0];  % mm
smiData.RigidTransform(1).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(1).axis = [0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(1).ID = "B[khau2_cover-1:-:lead_screw-2]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [-1.2462261575978624e-13 -30.008064533905213 7.6981947644887479e-14];  % mm
smiData.RigidTransform(2).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(2).axis = [0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(2).ID = "F[khau2_cover-1:-:lead_screw-2]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [0 505.00000000000011 0];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(3).ID = "B[lead_screw-2:-:new_end_effector-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [1.9937660530126538e-13 515 1.5266746404617535e-13];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(4).axis = [-0.57735026918962584 -0.57735026918962573 -0.57735026918962573];
smiData.RigidTransform(4).ID = "F[lead_screw-2:-:new_end_effector-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [400 -125.97455967290588 0];  % mm
smiData.RigidTransform(5).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(5).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(5).ID = "B[khau1_arm-1:-:khau2_cover-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [7.408111556479971e-15 -207.4745596729058 -2.7439268396097297e-14];  % mm
smiData.RigidTransform(6).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(6).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(6).ID = "F[khau1_arm-1:-:khau2_cover-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [60.000000000000057 406.06999999999999 0];  % mm
smiData.RigidTransform(7).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(7).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(7).ID = "B[new_DE_2023-1:-:khau1_arm-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [-1.1184327018016837e-13 -37 -1.3834472425374859e-12];  % mm
smiData.RigidTransform(8).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(8).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(8).ID = "F[new_DE_2023-1:-:khau1_arm-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [0 0 0];  % mm
smiData.RigidTransform(9).angle = 0;  % rad
smiData.RigidTransform(9).axis = [0 0 0];
smiData.RigidTransform(9).ID = "AssemblyGround[new_DE_2023-1:khau0_base-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(10).translation = [145.00000000000009 381.06999999999999 0];  % mm
smiData.RigidTransform(10).angle = 0;  % rad
smiData.RigidTransform(10).axis = [0 0 0];
smiData.RigidTransform(10).ID = "AssemblyGround[new_DE_2023-1:khau0_base_connector-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(11).translation = [145.00000000000006 30.000000000000028 0];  % mm
smiData.RigidTransform(11).angle = 0;  % rad
smiData.RigidTransform(11).axis = [0 0 0];
smiData.RigidTransform(11).ID = "AssemblyGround[new_DE_2023-1:khau0_base_support-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(12).translation = [0 0 0];  % mm
smiData.RigidTransform(12).angle = 0;  % rad
smiData.RigidTransform(12).axis = [0 0 0];
smiData.RigidTransform(12).ID = "RootGround[new_DE_2023-1]";


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(7).mass = 0.0;
smiData.Solid(7).CoM = [0.0 0.0 0.0];
smiData.Solid(7).MoI = [0.0 0.0 0.0];
smiData.Solid(7).PoI = [0.0 0.0 0.0];
smiData.Solid(7).color = [0.0 0.0 0.0];
smiData.Solid(7).opacity = 0.0;
smiData.Solid(7).ID = "";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.22695807807328738;  % kg
smiData.Solid(1).CoM = [0 5 0];  % mm
smiData.Solid(1).MoI = [52.95688488376706 102.13113513297934 52.95688488376706];  % kg*mm^2
smiData.Solid(1).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(1).color = [0.77647058823529413 0.75686274509803919 0.73725490196078436];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = "new_end_effector*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 9.5744060826409019;  % kg
smiData.Solid(2).CoM = [163.72610069571357 36.926043572874498 -0.00025752436263671061];  % mm
smiData.Solid(2).MoI = [22985.063889065816 256332.34414611544 245537.58477303636];  % kg*mm^2
smiData.Solid(2).PoI = [0.050147274082204596 0.21679343513976457 -11428.457983066333];  % kg*mm^2
smiData.Solid(2).color = [0.20000000000000001 0.20000000000000001 0.20000000000000001];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = "khau1_arm*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.78900536726907722;  % kg
smiData.Solid(3).CoM = [-0.00012093407899498624 221.14179949277639 0.00092398213247962488];  % mm
smiData.Solid(3).MoI = [20058.00361976881 52.656671913093582 20058.001868301915];  % kg*mm^2
smiData.Solid(3).PoI = [-0.063419069556692159 0.00060723706612499811 -0.03111362042266997];  % kg*mm^2
smiData.Solid(3).color = [0.65098039215686276 0.61960784313725492 0.58823529411764708];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = "lead_screw*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 20.914022595117437;  % kg
smiData.Solid(4).CoM = [39.75491986204063 162.86279479346592 -2.3159223067550866e-06];  % mm
smiData.Solid(4).MoI = [363028.60484277131 146869.752119704 403843.39906716306];  % kg*mm^2
smiData.Solid(4).PoI = [-0.0047793892386100208 -0.001408678259642049 -35993.434211217071];  % kg*mm^2
smiData.Solid(4).color = [0.20000000000000001 0.20000000000000001 0.20000000000000001];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = "khau0_base*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(5).mass = 2.8785275028518575;  % kg
smiData.Solid(5).CoM = [-108.19199372595585 14.891618632098849 0.043287992531263572];  % mm
smiData.Solid(5).MoI = [5535.6702738932536 16613.859130838537 11785.927900301993];  % kg*mm^2
smiData.Solid(5).PoI = [-3.0372090200302782 14.251769873493535 583.25170824856968];  % kg*mm^2
smiData.Solid(5).color = [0.20000000000000001 0.20000000000000001 0.20000000000000001];
smiData.Solid(5).opacity = 1;
smiData.Solid(5).ID = "khau0_base_connector*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(6).mass = 0.4723230430949184;  % kg
smiData.Solid(6).CoM = [-223.50819568320952 175.48349030900434 0];  % mm
smiData.Solid(6).MoI = [5619.4030538536708 1554.7520165220271 5632.1121769753781];  % kg*mm^2
smiData.Solid(6).PoI = [0 0 0.10158422513146931];  % kg*mm^2
smiData.Solid(6).color = [1 1 1];
smiData.Solid(6).opacity = 1;
smiData.Solid(6).ID = "khau0_base_support*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(7).mass = 1.0601825903681412;  % kg
smiData.Solid(7).CoM = [154.87663146170564 78.653332586573214 0.00024754457607211567];  % mm
smiData.Solid(7).MoI = [8443.1379775268651 30633.957909966026 35252.780253868194];  % kg*mm^2
smiData.Solid(7).PoI = [-0.0098186211144173346 0.020052134777809965 404.41140321930033];  % kg*mm^2
smiData.Solid(7).color = [1 1 1];
smiData.Solid(7).opacity = 1;
smiData.Solid(7).ID = "khau2_cover*:*Default";


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the CylindricalJoint structure array by filling in null values.
smiData.CylindricalJoint(1).Rz.Pos = 0.0;
smiData.CylindricalJoint(1).Pz.Pos = 0.0;
smiData.CylindricalJoint(1).ID = "";

smiData.CylindricalJoint(1).Rz.Pos = 7.7192373210330789;  % deg
smiData.CylindricalJoint(1).Pz.Pos = 0;  % mm
smiData.CylindricalJoint(1).ID = "[khau2_cover-1:-:lead_screw-2]";


%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(3).Rz.Pos = 0.0;
smiData.RevoluteJoint(3).ID = "";

smiData.RevoluteJoint(1).Rz.Pos = 55.167602202299697;  % deg
smiData.RevoluteJoint(1).ID = "[lead_screw-2:-:new_end_effector-1]";

smiData.RevoluteJoint(2).Rz.Pos = 23.252590819764258;  % deg
smiData.RevoluteJoint(2).ID = "[khau1_arm-1:-:khau2_cover-1]";

smiData.RevoluteJoint(3).Rz.Pos = -8.1439711191350863;  % deg
smiData.RevoluteJoint(3).ID = "[new_DE_2023-1:-:khau1_arm-1]";

