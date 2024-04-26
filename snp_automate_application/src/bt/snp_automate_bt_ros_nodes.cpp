#include <snp_automate_application/bt/snp_automate_bt_ros_nodes.h>
#include <snp_application/bt/utils.h>

namespace snp_automate_application
{
bool StartTrajModeNode::setRequest(typename Request::SharedPtr& /*request*/)
{
  return true;
}

BT::NodeStatus StartTrajModeNode::onResponseReceived(const typename Response::SharedPtr& response)
{
  switch(response->result_code.value)
  {
  case motoros2_interfaces::msg::MotionReadyEnum::READY:
    return BT::NodeStatus::SUCCESS;
  default:
    config().blackboard->set(snp_application::ERROR_MESSAGE_KEY, response->message);
    return BT::NodeStatus::FAILURE;
  }
}

bool StartPointQueueModeNode::setRequest(typename Request::SharedPtr& /*request*/)
{
  return true;
}

BT::NodeStatus StartPointQueueModeNode::onResponseReceived(const typename Response::SharedPtr& response)
{
  switch(response->result_code.value)
  {
  case motoros2_interfaces::msg::MotionReadyEnum::READY:
    return BT::NodeStatus::SUCCESS;
  default:
    config().blackboard->set(snp_application::ERROR_MESSAGE_KEY, response->message);
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace snp_application
