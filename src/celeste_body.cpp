#include "celestial_body.h"

CelestialBody::CelestialBody()
  : Node("celestial_body_node"), transform_({})
{
  marker_publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("marker", 10);

  timer_ = this->create_wall_timer(std::chrono::milliseconds(100), [this]() {
    publishMarker();
    publishTransform();
  });
}

void CelestialBody::publishMarker()
{
  // TODO: Implement logic to publish marker message
  // Example usage:
  // visualization_msgs::msg::Marker marker;
  // ...
  // marker_publisher_->publish(marker);
}

void CelestialBody::publishTransform()
{
  // TODO: Implement logic to publish transform message
  // Example usage:
  // geometry_msgs::msg::TransformStamped transform;
  // ...
  // transform_broadcaster_.sendTransform(transform);
}
