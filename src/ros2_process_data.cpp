#include <chrono>
#include <thread>

#include <rclcpp/rclcpp.hpp>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("ros2_process_data");

  while (rclcpp::ok()) {
    RCLCPP_WARN(node->get_logger(), "Waiting in loop");
    rclcpp::spin_some(node->get_node_base_interface());
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  rclcpp::shutdown();

  // Processing here
  RCLCPP_WARN(node->get_logger(), "Loop done, doing post-processing");
  std::this_thread::sleep_for(std::chrono::seconds(5));

  return 0;
}
