cmake_minimum_required(VERSION 3.5)
project(cpp_service_client)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(service_interfaces REQUIRED) # Our own Interface
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)

# For server
add_library(server_lib SHARED 
  src/example_server.cpp)
ament_target_dependencies(server_lib
  "service_interfaces"
  "rclcpp"
  "rclcpp_components")
rclcpp_components_register_node(server_lib
  PLUGIN "example_server_node::ExampleServerNode"
  EXECUTABLE example_server)
install(TARGETS
  server_lib
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# For client
add_executable(example_client src/example_client.cpp)
ament_target_dependencies(example_client
  "service_interfaces"
  "rclcpp")
install(TARGETS example_client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
