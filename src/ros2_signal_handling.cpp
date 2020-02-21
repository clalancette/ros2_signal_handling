#include <chrono>
#include <thread>

#include <rclcpp/rclcpp.hpp>


bool g_done = false;

void handler(int signum)
{
  (void)signum;
  RCLCPP_INFO(rclcpp::get_logger("ros2_signal_handler"), "custom signal handler called");
  g_done = true;
}

int main(int argc, char **argv)
{
  signal(SIGINT, handler);

  rclcpp::init(argc, argv);

  while (rclcpp::ok() && !g_done) {
    RCLCPP_INFO(rclcpp::get_logger("ros2_signal_handling"), "Waiting in loop");
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  rclcpp::shutdown();

  RCLCPP_INFO(rclcpp::get_logger("ros2_signal_handler"), "Loop done, doing post-processing");
  // Processing here
  std::this_thread::sleep_for(std::chrono::seconds(5));

  return 0;
}
