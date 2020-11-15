#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      // Setting QoS
      rclcpp::QoS qos_settings(10); // history depth is 10
#define QOS_HISTORY      1
#define QOS_RELIABILITY  1
#define QOS_DURABILITY   1
#define QOS_DEADLINE     1
#define QOS_LIFESPAN     1
#define QOS_LIVELINESS   1
#if QOS_HISTORY
      // History
      qos_settings.keep_last(10);
      qos_settings.keep_all();
#endif
#if QOS_RELIABILITY
      qos_settings.reliable();
      qos_settings.best_effort();
#endif
#if QOS_DURABILITY
      qos_settings.durability_volatile();
      qos_settings.transient_local();
#endif
#if QOS_DEADLINE
      qos_settings.deadline(std::chrono::milliseconds(2000));
#endif
#if QOS_LIFESPAN
      qos_settings.lifespan(std::chrono::milliseconds(2000));
#endif
#if QOS_LIVELINESS
      qos_settings.liveliness_lease_duration(std::chrono::milliseconds(2000));
#endif

      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", qos_settings, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
