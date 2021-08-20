#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      // Setting QoS
      rclcpp::QoS qos_settings(10); // history depth is 10
      rclcpp::PublisherOptions pub_options;
#define QOS_HISTORY      1
#define QOS_RELIABILITY  0
#define QOS_DURABILITY   1
#define QOS_DEADLINE     0
#define QOS_LIFESPAN     0
#define QOS_LIVELINESS   0
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

      pub_options.event_callbacks.deadline_callback =
        [](rclcpp::QOSDeadlineOfferedInfo & event) -> void
        {
          printf("Offered deadline missed: total %d delta %d\n", event.total_count, event.total_count_change);
        };
#endif
#if QOS_LIFESPAN
      qos_settings.lifespan(std::chrono::milliseconds(2000));
#endif
#if QOS_LIVELINESS
      qos_settings.liveliness(RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_TOPIC);
      qos_settings.liveliness_lease_duration(std::chrono::milliseconds(2000));
#endif

      publisher_ = this->create_publisher<std_msgs::msg::String>("topic", qos_settings, pub_options);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
