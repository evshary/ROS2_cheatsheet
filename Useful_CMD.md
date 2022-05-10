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
