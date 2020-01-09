# Introduction

## State

* Primary States (steady states):
  - unconfigured
  - inactive
  - active
  - shutdown
* Transition States (intermediate states):
  - configuring
  - activating
  - deactivating
  - cleaningup
  - shuttingdown

## Command

* Show the current lifecycle node
  - `ros2 lifecycle nodes`
* Show the available trasition of the node
  - `ros2 lifecycle list <node_name>`
* Get the current status
  - `ros2 lifecycle get <node_name>`
* Set the node status
  - `ros2 lifecycle set <node_name> <status>`

There are several communication interfaces:

* Publisher <node_name>__transition_event: publishes in case a transition is happening.
* Service <node_name>__get_state: query about the current state of the node.
  - `ros2 service call /lc_talker/get_state lifecycle_msgs/GetState`
* Service <node_name>__change_state: triggers a transition for the current node.
  - `ros2 service call /lc_talker/change_state lifecycle_msgs/ChangeState "{transition: {id: 2}}"`
  - The id of transition can be found by `ros2 msg show lifecycle_msgs/Transition`
* Other service interface can be found by `ros2 service list`

## Programming

* Create package
```sh
ros2 pkg create --build-type ament_cmake cpp_lifecycle_demo
```
* Add lifecycle_talker.cpp
* Add launch file
* Modify CMakeLists.txt: find_package, include_directories, add_executable, target_link_libraries, install
* Build and run
```sh
colcon build --packages-select cpp_lifecycle_demo
source install/local_setup.bash
ros2 launch cpp_lifecycle_demo lifecycle_demo.launch.py
ros2 lifecycle set /lc_talker configure
ros2 lifecycle set /lc_talker activate
```

# Reference

* [ROS Design: lifecycle](https://design.ros2.org/articles/node_lifecycle.html)
* [Management of nodes with managed lifecycles](https://index.ros.org/doc/ros2/Tutorials/Managed-Nodes/)
* [LifeCycle Introduction](https://github.com/ros2/demos/blob/master/lifecycle/README.rst)