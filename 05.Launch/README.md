# Introduction

## C++

* Create package
```sh
ros2 pkg create --build-type ament_cmake cpp_launch_demo
```
* Add "Install launch files" in CMakeLists.txt
* Create launch folder and write simple launch file.
* Build and run
```sh
colcon build --packages-select cpp_launch_demo
source install/local_setup.bash
ros2 launch cpp_launch_demo launch_demo.launch.py
# You can assign parameters
ros2 launch cpp_launch_demo launch_demo.launch.py cpu:=1
```

## Python

* Create package
```sh
ros2 pkg create --build-type ament_python py_launch_demo
```
* Add "Install launch files" in setup.py
  - Remember `import os` and `from glob import glob`
* Create launch folder and write simple launch file.
* Build and run
```sh
colcon build --packages-select py_launch_demo
source install/local_setup.bash
ros2 launch py_launch_demo launch_demo.launch.py
# Run different node by choosing action
ros2 launch py_launch_demo launch_demo.launch.py myaction:=listen
```

# Reference

* [Creating a launch file](https://index.ros.org/doc/ros2/Tutorials/Launch-Files/Creating-Launch-Files/)
* [Launching/monitoring multiple nodes with Launch](https://index.ros.org/doc/ros2/Tutorials/Launch-system/)