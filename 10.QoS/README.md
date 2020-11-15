# Introduction

The most important feature in ROS 2 is QoS. The QoS in ROS 2 is based on the one in DDS.

There are 6 QoS in ROS 2:

* Reliability: Ensure the data reliability (reliable / best effort)
* Durability: Provide history data to late-joiner or not (volatile / transient_local)
* History: Decide how old the data we provide (depth)
* Lifespan: Data will expire while exceeding its life time
* Liveliness: Ensure the existence of other entity
* Deadline: Alarm if data doesn't reach in time

These 6 QoS are independent with each other.

# Reference

* [Design: QoS](https://design.ros2.org/articles/qos.html)
* [About Quality of Service Settings](https://index.ros.org/doc/ros2/Concepts/About-Quality-of-Service-Settings/)
* [Demo Code](https://github.com/ros2/demos/tree/master/quality_of_service_demo)
* [C++ API for QoS](http://docs.ros2.org/latest/api/rclcpp/classrclcpp_1_1QoS.html)
* [Python API for QoS](http://docs.ros2.org/latest/api/rclpy/api/qos.html)
