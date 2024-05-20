import os
import launch

import launch_ros.actions
import launch.actions


def generate_launch_description():

    turtle_sim_node = launch_ros.actions.Node(
        package='turtlesim',
        executable='turtlesim_node',
        output='log',
        ros_arguments=['--ros-args', '--disable-stdout-logs']
    )

    joy_node = launch_ros.actions.Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        output='screen'
    )

    joystick_controller_node = launch_ros.actions.Node(
        package='joystick_controller',
        executable='turtlesim_client',
        name='joy_controller',
        output='screen',
        on_exit=launch.actions.Shutdown()
    )

    return launch.LaunchDescription([
        turtle_sim_node,
        joy_node,
        joystick_controller_node
    ])

if __name__ == '__main__':
    generate_launch_description()