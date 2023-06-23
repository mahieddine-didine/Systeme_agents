#include "mas_solarsystem/celestial_body.h"

CelestialBody::CelestialBody()
  : Node("celestial_body_node", rclcpp::NodeOptions().allow_undeclared_parameters(true).automatically_declare_parameters_from_overrides(true))
{
  marker_.header.frame_id = "sun_frame";
  marker_.header.stamp = this->now();
  marker_.ns = "solar_system";
  marker_.id = 0;
  marker_.type = visualization_msgs::msg::Marker::SPHERE;
  marker_.action = visualization_msgs::msg::Marker::ADD;
  marker_.pose.position.x = 0.0;
  marker_.pose.position.y = 0.0;
  marker_.pose.position.z = 0.0;
  marker_.pose.orientation.x = 0.0;
  marker_.pose.orientation.y = 0.0;
  marker_.pose.orientation.z = 0.0;
  marker_.pose.orientation.w = 1.0;
  marker_.scale.x = 1.0;
  marker_.scale.y = 1.0;
  marker_.scale.z = 1.0;
  marker_.color.r = 1.0;
  marker_.color.g = 0.0;
  marker_.color.b = 0.0;
  marker_.color.a = 1.0;

  timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&CelestialBody::publishMarker, this));
}

void CelestialBody::publishMarker()
{
  marker_.header.stamp = this->now();
  marker_.pose.position.x += 0.1;  // Exemple de déplacement
  marker_.pose.position.y += 0.1;  // Exemple de déplacement

  auto marker_pub = this->create_publisher<visualization_msgs::msg::Marker>("solar_system_marker", 10);
  marker_pub->publish(marker_);
}

void CelestialBody::publishTransform()
{
  auto transform_stamped = std::make_shared<geometry_msgs::msg::TransformStamped>();
  transform_stamped->header.stamp = this->now();
  transform_stamped->header.frame_id = "sun_frame";
  transform_stamped->child_frame_id = "planet_frame";
  transform_stamped->transform.translation.x = 1.0;  // Exemple de position relative
  transform_stamped->transform.translation.y = 1.0;  // Exemple de position relative
  transform_stamped->transform.translation.z = 1.0;  // Exemple de position relative
  transform_stamped->transform.rotation.x = 0.0;
  transform_stamped->transform.rotation.y = 0.0;
  transform_stamped->transform.rotation.z = 0.0;
  transform_stamped->transform.rotation.w = 1.0;

  tf_broadcaster_.sendTransform(*transform_stamped);
}

