#pragma once

#include <snp_application/snp_widget.h>

namespace snp_automate_application
{
class AutomateWidget : public snp_application::SNPWidget
{
public:
  explicit AutomateWidget(rclcpp::Node::SharedPtr rviz_node, QWidget* parent = nullptr);

protected:
  BT::BehaviorTreeFactory createBTFactory(int ros_short_timeout, int ros_long_timeout) override;
};

}  // namespace snp_automate_application
