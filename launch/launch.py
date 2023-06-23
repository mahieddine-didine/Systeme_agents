from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    mas_solarsystem_params = PathJoinSubstitution(
        [
            FindPackageShare("mas_solarsystem"),
            "cfg",
            "mas_solarsystem_params.yaml"
        ]
    )

    sun_node = Node(
        package="mas_solarsystem",
        executable="celestial_body_node",
        name="sun_node",
        parameters=[
            mas_solarsystem_params
        ],
        remappings=[
            ("/marker", "/sun_marker"),
        ],
        output="screen"
    )

    return LaunchDescription([sun_node])