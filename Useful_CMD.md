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

# Tips

* Show debug message
  - ROS 1: Modify `$ROS_ROOT/config/rosconsole.config`
