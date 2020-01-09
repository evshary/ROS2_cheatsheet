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
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils)
find_package(rmw REQUIRED)
find_package(std_msgs REQUIRED)

add_library(services_library SHARED
  src/add_two_ints_server.cpp
  src/add_two_ints_client.cpp)
target_compile_definitions(services_library
  PRIVATE "DEMO_NODES_CPP_BUILDING_DLL")
ament_target_dependencies(services_library
  "example_interfaces"
  "rclcpp"
  "rclcpp_components"
  "rcutils"
  "std_msgs")
rclcpp_components_register_node(services_library
  PLUGIN "demo_nodes_cpp::ServerNode"
  EXECUTABLE add_two_ints_server)
install(TARGETS
  services_library
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
ament_target_dependencies(add_two_ints_client
  "example_interfaces"
  "rclcpp"
  "rcutils"
  "std_msgs")
install(TARGETS add_two_ints_client
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
