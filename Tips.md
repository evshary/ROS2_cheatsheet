# Tips

# Enable multicast in loopback interface

If you don't have network and can only use loopback network, you need to enable multicast on loopback interface.

```bash
sudo ip route add 224.0.0.0/4 dev lo
sudo ip link set lo multicast on
```

* Verification

```bash
# terminal 1
ros2 multicast receive
# terminal 2
ros2 multicast send
```

# Remapping

* Remap:
  - namespace to `/demo`
  - node name to `my_talker`
  - topic from `chatter` to `my_topic`

```bash
ros2 run demo_nodes_cpp talker --ros-args -r __ns:=/demo -r __node:=my_talker -r chatter:=my_topic
```

* [Passing ROS arguments to nodes via the command-line](https://docs.ros.org/en/foxy/How-To-Guides/Node-arguments.html)

# Log

While running launch with failures, you can view the log from `~/.ros/log/`

# FAQ

* If you met `Failed to find a free participant index for domain 0` (while using `ROS_LOCALHOST_ONLY`)
   - This is related to CycloneDDS. You can enable multicast on `lo`
   - https://github.com/eclipse-cyclonedds/cyclonedds/issues/1400

* If you met `action_exc: create_thread: action_exceptio: no free slot`
   - This is due to CycloneDDS thread limitation
   - https://github.com/ros2/rmw_cyclonedds/issues/268

