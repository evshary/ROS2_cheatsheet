#include "rclcpp/rclcpp.hpp"

#include "service_interfaces/srv/example_service.hpp"

using namespace std::chrono_literals;  // used by 1s

service_interfaces::srv::ExampleService::Response::SharedPtr send_request(
    rclcpp::Node::SharedPtr node,
    rclcpp::Client<service_interfaces::srv::ExampleService>::SharedPtr client,
    service_interfaces::srv::ExampleService::Request::SharedPtr request)
{
    auto result = client->async_send_request(request);
    // Waiting
    if (rclcpp::spin_until_future_complete(node, result) == 
        rclcpp::executor::FutureReturnCode::SUCCESS)
    {
        return result.get();
    } else {
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    // Node name
    auto node = rclcpp::Node::make_shared("example_client");
    // Ceraete a client to query service name "example_service_name"
    auto client = node->create_client<service_interfaces::srv::ExampleService>("example_service_name");

    // Build the request
    auto request = std::make_shared<service_interfaces::srv::ExampleService::Request>();
    request->param = 1;

    // Waiting until the service is up
    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(node->get_logger(), "Catch interrupt and stop the program!");
            return 0;
        }
        RCLCPP_INFO(node->get_logger(), "Waiting for service...");
    }

    // Send the request
    auto result = send_request(node, client, request);
    if (result) {
        RCLCPP_INFO(node->get_logger(), "result=%d", result->result);
    } else {
        RCLCPP_ERROR(node->get_logger(), "Catch interrupt and stop the program!");
    }

    rclcpp::shutdown();

    return 0;
}