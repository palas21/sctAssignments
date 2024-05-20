import os
import launch

import launch_ros.actions

def generate_launch_description():
    yaml_file_path = os.path.join(
        os.path.dirname(__file__),
        '..',
        'config',
        'params.yaml'
    )

    image_publisher_node = launch_ros.actions.Node(
        package='image_converter',
        executable='image_publisher',
        parameters=[yaml_file_path]
    )

    image_subscriber_node = launch_ros.actions.Node(
        package='image_converter',
        executable='image_subscriber',
        parameters=[yaml_file_path]
    )

    return launch.LaunchDescription([
        image_publisher_node,
        image_subscriber_node
    ])

if __name__ == '__main__':
    generate_launch_description()