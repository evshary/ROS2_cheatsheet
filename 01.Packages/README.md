# Introduction

* You can create a ROS2 package with the following command.
```sh
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
# For C++ project
ros2 pkg create --build-type ament_cmake --node-name <node_name> <package_name>
# For Python project
ros2 pkg create --build-type ament_python --node-name <node_name> <package_name>
```
* Build the package
```
cd ~/ros2_ws
colcon build --packages-select <package_name>
source install/setup.bash
```
* Run the package
```
ros2 run <node_name> <package_name>
```

# Reference

* [Creating a ROS 2 package](https://index.ros.org/doc/ros2/Tutorials/Creating-A-ROS2-Package/)