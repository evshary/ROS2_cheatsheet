import os
import ament_index_python.packages
import launch
import launch.actions
import launch.substitutions
import launch_ros.actions
import launch.conditions

def generate_launch_description():
    enable_talker = launch.substitutions.LaunchConfiguration('enable_talker', default='true')
    enable_listener = launch.substitutions.LaunchConfiguration('enable_listener', default='true')
    enable_launch = launch.substitutions.LaunchConfiguration('enable_launch', default='false')
    cpu = launch.substitutions.LaunchConfiguration('cpu', default='8')

    # Node name will become <USER>_nodename
    declare_node_prefix = launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names')
    talker_node = launch_ros.actions.Node(
            package='demo_nodes_cpp',
            executable='talker',
            output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'talker'],
            condition=launch.conditions.IfCondition(enable_talker))
    listener_node = launch_ros.actions.Node(
            package='demo_nodes_cpp',
            executable='listener',
            output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'listener'],
            condition=launch.conditions.IfCondition(enable_listener))
    stress_process = launch.actions.ExecuteProcess(
            cmd = ['stress',
                   '-c',
                   cpu
                   ],
            output='screen')
    # This means run "ros2 launch demo_nodes_cpp talker_listner.launch.py"
    another_launch = launch.actions.IncludeLaunchDescription(
        [os.path.join(ament_index_python.packages.get_package_share_directory('demo_nodes_cpp'), 'launch'),
         '/topics/talker_listener.launch.py'],
        condition=launch.conditions.IfCondition(enable_launch)
    )
    ld = launch.LaunchDescription()
    ld.add_action(declare_node_prefix)
    ld.add_action(talker_node)
    ld.add_action(listener_node)
    ld.add_action(stress_process)
    ld.add_action(another_launch)
    return ld