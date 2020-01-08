# Introduction

## C++

* Create project
```sh
ros2 pkg create --build-type ament_cmake cpp_pubsub
```
* Add pub.cpp, sub.cpp in `ros2_ws/src/cpp_pubsub/src`
* Open package.xml: Modify description, license, version, and add exec_depend field.
* Open CMakeLists.txt: Add find_package, add_executable, ament_target_dependencies, install field.
* Build and run
```sh
colcon build --packages-select cpp_pubsub
source install/setup.bash
ros2 run cpp_pubsub listener &
ros2 run cpp_pubsub talker
```

## Python

* Create project
```sh
ros2 pkg create --build-type ament_python py_pubsub
```
* Add pub.py, sub.py in `ros2_ws/src/py_pubsub/py_pubsub`
* Open package.xml: Modify description, license, version, and add exec_depend field.
* Open setup.py: Modify description, license, version, and add entry_point.
* Build and run
```sh
colcon build --packages-select py_pubsub
source install/setup.bash
ros2 run py_pubsub listener &
ros2 run py_pubsub talker
```

# Reference

* [Writing a simple publisher and subscriber (C++)](https://index.ros.org/doc/ros2/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber/)
* [Writing a simple publisher and subscriber (Python)](https://index.ros.org/doc/ros2/Tutorials/Writing-A-Simple-Py-Publisher-And-Subscriber/)