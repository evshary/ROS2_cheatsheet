# Introduction

## Command

* Discover available components
  - `ros2 component types`
* Run composition with container
```sh
# Run component container
ros2 run rclcpp_components component_container
# View all the container
ros2 component list
# Load talker and listener
# ros2 component load /ComponentManager <package_name> <plugin_name>
ros2 component load /ComponentManager composition composition::Talker
ros2 component load /ComponentManager composition composition::Listener
```
* Unload component
  - `ros2 component unload /ComponentManager <component_number>`
* Run standalone component
  - `ros2 component standalone <package_name> <plugin_name>`
  - For example, `ros2 component standalone composition composition::Talker`

## Programming

* Create package
```sh
ros2 pkg create --build-type ament_cmake cpp_component_demo
```
* Add talker_component.cpp
* Add launch file
* Modify CMakeLists.txt: find_package, add_library, ament_target_dependencies, rclcpp_components_register_nodes, install
* Build and run
```sh
colcon build --packages-select cpp_component_demo
source install/local_setup.bash
ros2 launch cpp_component_demo composition_demo.launch.py
```

# Reference

* [Composing multiple nodes in a single processROS2 component wiki](https://index.ros.org/doc/ros2/Tutorials/Composition/)
* [Example code for running component](https://github.com/ros2/demos/tree/master/composition)