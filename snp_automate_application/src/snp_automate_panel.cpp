#include <snp_automate_application/snp_automate_widget.h>

#include <QMessageBox>
#include <QVBoxLayout>
#include <rviz_common/panel.hpp>
#include <rviz_common/display_context.hpp>

namespace snp_automate_application
{
class AutomatePanel : public rviz_common::Panel
{
public:
  void onInitialize() override
  {
    try
    {
      auto rviz_node = getDisplayContext()->getRosNodeAbstraction().lock()->get_raw_node();

      auto layout = new QVBoxLayout();
      layout->addWidget(new AutomateWidget(rviz_node, this));
      setLayout(layout);
    }
    catch (const std::exception& ex)
    {
      QMessageBox::warning(this, "Error", ex.what());
    }
  }
};

}  // namespace snp_automate_application

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(snp_automate_application::AutomatePanel, rviz_common::Panel)
