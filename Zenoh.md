# Run ROS with Zenoh

Sometimes we don't want DDS discovery traffic goes outside the host, and we want to use Zenoh instead.
zenoh-bridge-dds is a good choice.

* Build zenoh-bridge-dds in host 1 and host 2

* In host 1

```bash
# terminal 1
./target/release/zenoh-bridge-dds -f -e tcp/x.x.x.x:7447 --dds-localhost-only
# terminal 2
ros2 daemon stop # sometimes ros2 daemon might cache data
ROS_LOCALHOST_ONLY=1 RMW_IMPLEMENTATION=rmw_cyclonedds_cpp ros2 run demo_nodes_cpp talker
```

* In host 2

```bash
# terminal 1
./target/release/zenoh-bridge-dds -f -l tcp/0.0.0.0:7447 --dds-localhost-only
# terminal 2
ros2 daemon stop # sometimes ros2 daemon might cache data
ROS_LOCALHOST_ONLY=1 RMW_IMPLEMENTATION=rmw_cyclonedds_cpp ros2 topic echo /chatter
```
