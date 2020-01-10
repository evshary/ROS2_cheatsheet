# Introduction

## Notice

* Refer to [here](https://index.ros.org/doc/ros2/Concepts/About-ROS-Interfaces/) for the basic type.
* The name of interface should be like this "ThisIsExample.srv", not like this "this_is_example.srv".
* If you want to use the service interface,
  - `#include "pkg_name/srv/this_is_example.hpp"`
  - The type of the variable will be `pkg_name::srv::ThisIsExample`
  - Add `pkg_name` for `<build_depend>` and `<exec_depend>` in package.xml
  - Add `pkg_name` for `find_package` and `ament_target_dependencies`

## Programming

* Create Package
```sh
ros2 pkg create --build-type ament_cmake service_interface
```
* Modify package.xml
```
<buildtool_depend>ament_cmake</buildtool_depend>
<buildtool_depend>rosidl_default_generators</buildtool_depend>
<build_depend>builtin_interfaces</build_depend>  
<exec_depend>rosidl_default_runtime</exec_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```
* Modfiy CMakList.txt
```
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/ExampleInterface.srv"
)
ament_export_dependencies(rosidl_default_runtime)
```
* Build
```
colcon build --packages-select service_interface
```

# Reference

* [About ROS 2 Interfaces](https://index.ros.org/doc/ros2/Concepts/About-ROS-Interfaces/)