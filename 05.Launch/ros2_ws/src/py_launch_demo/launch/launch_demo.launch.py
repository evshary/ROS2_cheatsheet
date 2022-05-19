import launch
import launch.actions
import launch.substitutions
import launch_ros.actions
import launch.conditions


def generate_launch_description():
    # We demo how to do different actions based on settings
    myaction = launch.substitutions.LaunchConfiguration('myaction', default='talk')
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='demo_nodes_cpp',
            executable='talker',
            output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'talker'],
            condition=launch.conditions.IfCondition(launch.substitutions.PythonExpression(['"', myaction, '" == "talk"']))),
        launch_ros.actions.Node(
            package='demo_nodes_cpp',
            executable='listener',
            output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'listener'],
            condition=launch.conditions.IfCondition(launch.substitutions.PythonExpression(['"', myaction, '" == "listen"']))),
    ])