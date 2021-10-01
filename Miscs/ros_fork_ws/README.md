# fork with ROS

This example is used to test fork function with ROS 2.

# Build & Run

```bash
# Source ROS 2 foxy
colcon build
ros2 run fork_pkg fork_node
```

# Note

* Only one node is available if running with CycloneDDS. Not sure why.

