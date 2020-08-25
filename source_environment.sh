echo "source $(pwd)/devel/setup.bash" >> ~/.bashrc
echo "export GAZEBO_MODEL_PATH=:~/project/some/Firmware/Tools/sitl_gazebo/models:~/gazebo_models" >> ~/.bashrc
echo "source ~/project/some/Firmware/Tools/setup_gazebo.bash ~/project/some/Firmware ~/project/some/Firmware/build/px4_sitl_default" >> ~/.bashrc
echo "export ROS_PACKAGE_PATH=\$ROS_PACKAGE_PATH:~/project/some/Firmware" >> ~/.bashrc
echo "export ROS_PACKAGE_PATH=\$ROS_PACKAGE_PATH:~/project/some/Firmware/Tools/sitl_gazebo" >> ~/.bashrc
source ~/.bashrc
echo "SUCCEED,  No need to repeat it."
