#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "service_interfaces/srv/example_service.hpp"

namespace example_server_node
{

class ExampleServerNode : public rclcpp::Node
{
public:
  explicit ExampleServerNode(const rclcpp::NodeOptions & options)
  : Node("example_server", options)
  {
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    auto handle_example_service =
      [this](const std::shared_ptr<rmw_request_id_t> request_header,
        const std::shared_ptr<service_interfaces::srv::ExampleService::Request> request,
        std::shared_ptr<service_interfaces::srv::ExampleService::Response> response) -> void
      {
        (void)request_header;
        RCLCPP_INFO(this->get_logger(), "Incoming request: param=%d", request->param);
        response->result = 0;
      };
    // Create a service that will use the callback function to handle requests. The service's name is example_service_name.
    srv_ = create_service<service_interfaces::srv::ExampleService>("example_service_name", handle_example_service);
  }

private:
  rclcpp::Service<service_interfaces::srv::ExampleService>::SharedPtr srv_;
};

}

RCLCPP_COMPONENTS_REGISTER_NODE(example_server_node::ExampleServerNode)