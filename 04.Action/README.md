# Introduction

Consist of 3 parts: goal, result, feedback.
The “action client” node sends a goal to an “action server” node that acknowledges the goal and returns a stream of feedback and a result.

## Command

* Show action list
  - `ros2 action list`
  - Also show type: `ros2 action list -t`
* Show action info
  - `ros2 action info <action>`
* Send goal
  - `ros2 action send_goal <action_name> <action_type> <values>`
  - To receive feedback: `ros2 action send_goal <action_name> <action_type> <values> --feedback`

## Interface

* Create package
```sh
ros2 pkg create --build-type ament_cmake interface_action_demo
```
* Add action file.
* Modify package.xml: Add buildtool_depend, depend, member_of_group.
* Modify CMakeLists.txt: Add find_package, rosidl_generate_interfaces.
* Build
```sh
colcon build --packages-select interface_action_demo
```

## C++

* Create package
```sh
ros2 pkg create --build-type ament_cmake cpp_action_demo
```
* Add fibonacci_action_client.cpp, fibonacci_action_server.cpp
* Modify CMakeLists.txt: find_package, add_library, target_compile_definitions, ament_target_dependencies, rclcpp_components_register_node, install
* Build and run
```sh
colcon build --packages-select cpp_action_demo
source install/local_setup.bash
ros2 run cpp_action_demo fibonacci_action_server &
ros2 run cpp_action_demo fibonacci_action_client
# Use command line act as client
ros2 action send_goal fibonacci interface_action_demo/action/Fibonacci "{order: 5}" --feedback
```

## Python

* Create package
```sh
ros2 pkg create --build-type ament_python py_action_demo
```
* Add fibonacci_action_server.py, fibonacci_action_client.py
* Open package.xml: Modify description, license, version, and add depend, exec_depend field.
* Open setup.py: Modify description, license, version, and add entry_point.
* Build and run
```sh
colcon build --packages-select py_action_demo
source install/local_setup.bash
ros2 run py_action_demo fibonacci_action_server &
ros2 run py_action_demo fibonacci_action_client
```

# Reference

* [Actions](https://index.ros.org/doc/ros2/Tutorials/Actions/)
* [Understanding ROS 2 actions](https://index.ros.org/doc/ros2/Tutorials/Understanding-ROS2-Actions/)
* [Demo Code](https://github.com/ros2/demos/tree/master/action_tutorials)