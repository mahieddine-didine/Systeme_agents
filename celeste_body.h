#ifndef CELESTIAL_BODY_H
#define CELESTIAL_BODY_H

#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>

class CelestialBody : public rclcpp::Node {
public:
  CelestialBody();

private:
  void publishMarker();
  void publishTransform();

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_publisher_;
  tf2_ros::TransformBroadcaster transform_broadcaster_;
  geometry_msgs::msg::TransformStamped transform_;
};

#endif  // CELESTIAL_BODY_H
