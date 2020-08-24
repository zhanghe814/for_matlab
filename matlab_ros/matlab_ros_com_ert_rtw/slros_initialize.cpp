#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "matlab_ros_com";

// For Block matlab_ros_com/Subscribe
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped> Sub_matlab_ros_com_1;

// For Block matlab_ros_com/Subscribe1
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped> Sub_matlab_ros_com_25;

// For Block matlab_ros_com/Publish UAV1 Pose
SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped> Pub_matlab_ros_com_7;

// For Block matlab_ros_com/Publish UAV1 Velocity
SimulinkPublisher<geometry_msgs::TwistStamped, SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped> Pub_matlab_ros_com_37;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

