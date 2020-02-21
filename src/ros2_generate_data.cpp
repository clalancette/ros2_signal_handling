#include <chrono>
#include <thread>

#include <rclcpp/rclcpp.hpp>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  RCLCPP_WARN(rclcpp::get_logger("ros2_generate_data"), "Starting to generate data");

  int count = 0;
  while (rclcpp::ok() && count < 40) {
    // simulate generating some data here, then quitting
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    count++;
  }

  rclcpp::shutdown();

  RCLCPP_WARN(rclcpp::get_logger("ros2_generate_data"), "Quitting");

  return 0;
}
