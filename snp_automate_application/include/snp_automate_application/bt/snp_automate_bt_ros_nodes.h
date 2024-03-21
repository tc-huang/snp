#pragma once

#include <snp_application/bt/snp_bt_ros_nodes.h>
#include <motoros2_interfaces/srv/write_single_io.hpp>
#include <motoros2_interfaces/srv/read_single_io.hpp>
#include <motoros2_interfaces/srv/start_traj_mode.hpp>
#include <motoros2_interfaces/srv/start_point_queue_mode.hpp>

static const std::string CONTROLLER_JOINT_NAMES_PARAM = "controller_joint_names";

namespace snp_automate_application
{
// class WriteSingleIONode : public snp_application::SnpRosServiceNode<motoros2_interfaces::srv::WriteSingleIO>
// {
// public:
//   inline static std::string ADDRESS_KEY = "address";
//   inline static std::string VALUE_KEY = "value";
//   static BT::PortsList providedPorts()
//   {
//     return providedBasicPorts({BT::InputPort(ADDRESS_KEY), BT::InputPort(VALUE_KEY)});
//   }
//   using snp_application::SnpRosServiceNode<motoros2_interfaces::srv::WriteSingleIO>::SnpRosServiceNode;

//   bool setRequest(typename Request::SharedPtr& request) override;
//   BT::NodeStatus onResponseReceived(const typename Response::SharedPtr& response) override;
// };

// class ReadSingleIONode : public snp_application::SnpRosServiceNode<motoros2_interfaces::srv::ReadSingleIO>
// {
// public:
//   inline static std::string ADDRESS_KEY = "address";
//   inline static std::string VALUE_KEY = "value";
//   static BT::PortsList providedPorts()
//   {
//     return providedBasicPorts({BT::InputPort(ADDRESS_KEY), BT::OutputPort(VALUE_KEY)});
//   }
//   using snp_application::SnpRosServiceNode<motoros2_interfaces::srv::ReadSingleIO>::SnpRosServiceNode;

//   bool setRequest(typename Request::SharedPtr& request) override;
//   BT::NodeStatus onResponseReceived(const typename Response::SharedPtr& response) override;
// };

class StartTrajModeNode : public snp_application::SnpRosServiceNode<motoros2_interfaces::srv::StartTrajMode>
{
public:
  using snp_application::SnpRosServiceNode<motoros2_interfaces::srv::StartTrajMode>::providedPorts;
  using snp_application::SnpRosServiceNode<motoros2_interfaces::srv::StartTrajMode>::SnpRosServiceNode;

  bool setRequest(typename Request::SharedPtr& request) override;
  BT::NodeStatus onResponseReceived(const typename Response::SharedPtr& response) override;
};

class StartPointQueueModeNode : public snp_application::SnpRosServiceNode<motoros2_interfaces::srv::StartPointQueueMode>
{
public:
  using snp_application::SnpRosServiceNode<motoros2_interfaces::srv::StartPointQueueMode>::providedPorts;
  using snp_application::SnpRosServiceNode<motoros2_interfaces::srv::StartPointQueueMode>::SnpRosServiceNode;

  bool setRequest(typename Request::SharedPtr& request) override;
  BT::NodeStatus onResponseReceived(const typename Response::SharedPtr& response) override;
};

// class AddJointsToTrajectoryNode : public BT::RosTopicSubNode<sensor_msgs::msg::JointState>
// {
// public:
//   inline static std::string TRAJECTORY_INPUT_PORT_KEY = "input";
//   inline static std::string TRAJECTORY_OUTPUT_PORT_KEY = "output";
//   inline static BT::PortsList providedPorts()
//   {
//     return providedBasicPorts({ BT::InputPort<trajectory_msgs::msg::JointTrajectory>(TRAJECTORY_INPUT_PORT_KEY),
//                                BT::OutputPort<trajectory_msgs::msg::JointTrajectory>(TRAJECTORY_OUTPUT_PORT_KEY) });
//   }
//   using BT::RosTopicSubNode<sensor_msgs::msg::JointState>::RosTopicSubNode;

//   BT::NodeStatus onTick(const typename sensor_msgs::msg::JointState::SharedPtr& last_msg) override;
// };

}  // namespace snp_automate_application
