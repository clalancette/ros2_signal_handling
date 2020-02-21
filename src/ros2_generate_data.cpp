#include <chrono>
#include <thread>

#include <rclcpp/rclcpp.hpp>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  int count = 0;
  while (rclcpp::ok() && count < 20) {
    // simulate generating some data here, then quitting
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    count++;
  }

  rclcpp::shutdown();

  return 0;
}
