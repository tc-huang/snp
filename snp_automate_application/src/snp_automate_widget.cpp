#include <snp_automate_application/snp_automate_widget.h>
#include <snp_automate_application/bt/snp_automate_bt_ros_nodes.h>

namespace snp_automate_application
{
AutomateWidget::AutomateWidget(rclcpp::Node::SharedPtr rviz_node, QWidget* parent)
    : snp_application::SNPWidget(rviz_node, parent)
{
  bt_node_->declare_parameter<std::vector<std::string>>(CONTROLLER_JOINT_NAMES_PARAM, {});
}

BT::BehaviorTreeFactory AutomateWidget::createBTFactory(int ros_short_timeout, int ros_long_timeout)
{
  BT::BehaviorTreeFactory factory = SNPWidget::createBTFactory(ros_short_timeout, ros_long_timeout);

  BT::RosNodeParams ros_params;
  ros_params.nh = bt_node_;
  ros_params.wait_for_server_timeout = std::chrono::seconds(0);
  ros_params.server_timeout = std::chrono::seconds(ros_short_timeout);

  factory.registerNodeType<StartTrajModeNode>("StartTrajMode", ros_params);
  factory.registerNodeType<StartPointQueueModeNode>("StartPointQueueMode", ros_params);
  // factory.registerNodeType<WriteSingleIONode>("WriteSingleIO", ros_params);
  // factory.registerNodeType<ReadSingleIONode>("ReadSingleIO", ros_params);
  // factory.registerNodeType<AddJointsToTrajectoryNode>("AddJointsToTrajectory", ros_params);

  return factory;
}

}  // namespace snp_automate_application
