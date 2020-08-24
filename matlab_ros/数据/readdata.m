uav1_pos_x=uav1x.signals.values;
uav1_pos_y=uav1y.signals.values;
uav1_pos_z=uav1z.signals.values;
uav2_pos_x=uav2x.signals.values;
uav2_pos_y=uav2y.signals.values;
uav2_pos_z=uav2z.signals.values;
uav3_pos_x=uav3x.signals.values;
uav3_pos_y=uav3y.signals.values;
uav3_pos_z=uav3z.signals.values;
flag=0;
figure(1)
if flag==1
plot(uav1_pos_x,uav1_pos_y);
else
plot3(uav1_pos_x,uav1_pos_y,uav1_pos_z);
end
figure(2)
if flag==1
plot(uav2_pos_x,uav2_pos_y);
else
plot3(uav2_pos_x,uav2_pos_y,uav2_pos_z)
end
figure(3)
if flag==1
plot(uav3_pos_x,uav3_pos_y);
else
plot3(uav3_pos_x,uav3_pos_y,uav3_pos_z);
end
figure(4)
if flag==1
plot(uav1_pos_x,uav1_pos_y);
hold on
plot(uav2_pos_x,uav2_pos_y);
hold on
plot(uav3_pos_x,uav3_pos_y);
else
plot3(uav1_pos_x,uav1_pos_y,uav1_pos_z);
hold on
plot3(uav2_pos_x,uav2_pos_y,uav2_pos_z);
hold on
plot3(uav3_pos_x,uav3_pos_y,uav3_pos_z);
end