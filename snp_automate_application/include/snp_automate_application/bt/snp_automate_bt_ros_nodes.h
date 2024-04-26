#pragma once

#include <snp_application/bt/snp_bt_ros_nodes.h>
#include <motoros2_interfaces/srv/write_single_io.hpp>
#include <motoros2_interfaces/srv/read_single_io.hpp>
#include <motoros2_interfaces/srv/start_traj_mode.hpp>
#include <motoros2_interfaces/srv/start_point_queue_mode.hpp>

namespace snp_automate_application
{
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

}  // namespace snp_automate_application
