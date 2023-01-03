# Tips

# Developing

Use C++ autocomplete in vscode

1. Download C/C++ plugins
2. Compile with option: `colcon build --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
3. Link `compile_commands.json` to root folder: `ln -s ../build/compile_commands.json .`
4. Restart vscode, and C/C++ plugin will ask you.

Use python autocomplete in vscode

1. Download Python plugin
2. Create .env file under the workspace with the content "PYTHONPATH=/opt/ros/galactic/lib/python3.8/site-packages"

# Enable multicast in loopback interface

If you don't have network and can only use loopback network, you need to enable multicast on loopback interface.

```bash
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

# rosdep

* If you want to use EOL ROS distribution

```shell
# Update all EOL distros
rosdep update --include-eol-distros
# Select the distro you want, e.g. galactic
rosdep update --rosdistro=galactic
# Also need to assign ROS distro while updating
rosdep install -y --from-paths src --ignore-src --rosdistro $ROS_DISTRO
```

# FAQ

* If you met `Failed to find a free participant index for domain 0` (while using `ROS_LOCALHOST_ONLY`)
   - This is related to CycloneDDS. You can enable multicast on `lo`
   - https://github.com/eclipse-cyclonedds/cyclonedds/issues/1400

* If you met `action_exc: create_thread: action_exceptio: no free slot`
   - This is due to CycloneDDS thread limitation
   - https://github.com/ros2/rmw_cyclonedds/issues/268

* If you found that ROS 2 has strange behaviors, stop ROS 2 daemon

```shell
ros2 daemon stop
ros2 daemon status
```
