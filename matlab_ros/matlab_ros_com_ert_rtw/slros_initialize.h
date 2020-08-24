#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block matlab_ros_com/Subscribe
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped> Sub_matlab_ros_com_1;

// For Block matlab_ros_com/Subscribe1
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped> Sub_matlab_ros_com_25;

// For Block matlab_ros_com/Publish UAV1 Pose
extern SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped> Pub_matlab_ros_com_7;

// For Block matlab_ros_com/Publish UAV1 Velocity
extern SimulinkPublisher<geometry_msgs::TwistStamped, SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped> Pub_matlab_ros_com_37;

void slros_node_init(int argc, char** argv);

#endif
