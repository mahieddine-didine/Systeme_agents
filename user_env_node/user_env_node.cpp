#include "user_env_node.h"

UserEnvNode::UserEnvNode()
  : Node("user_env_node")
{
  // Création des éditeurs de position
  earth_position_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("earth_position", 10);
  mars_position_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("mars_position", 10);

  // Création du service de réinitialisation de la simulation
  reset_simulation_service_ = this->create_service<std_srvs::srv::Empty>("reset_sim",
    [this](const std::shared_ptr<std_srvs::srv::Empty::Request> request,
           std::shared_ptr<std_srvs::srv::Empty::Response> response) {
      resetSimulation();
    });

  // Récupération des paramètres d'échelle d'espace et de temps
  space_scale_param_ = this->declare_parameter("space_scale", 1.0);
  time_scale_param_ = this->declare_parameter("time_scale", 1.0);
  space_scale_ = space_scale_param_.get_value<double>();
  time_scale_ = time_scale_param_.get_value<double>();

  // Création de la boucle de publication de position de la Terre et de Mars
  auto timer_earth = this->create_wall_timer(std::chrono::milliseconds(1000), [this]() {
    publishEarthPosition();
  });

  auto timer_mars = this->create_wall_timer(std::chrono::milliseconds(2000), [this]() {
    publishMarsPosition();
  });
}

void UserEnvNode::publishEarthPosition()
{
  geometry_msgs::msg::Point earth_position;
  // Obtenir la position actuelle de la Terre (exemple)
  // earth_position.x = ...;
  // earth_position.y = ...;
  // earth_position.z = ...;

  earth_position_publisher_->publish(earth_position);
}

void UserEnvNode::publishMarsPosition()
{
  geometry_msgs::msg::Point mars_position;
  // Obtenir la position actuelle de Mars (exemple)
  // mars_position.x = ...;
  // mars_position.y = ...;
  // mars_position.z = ...;

  mars_position_publisher_->publish(mars_position);
}

void UserEnvNode::resetSimulation()
{
  // Code pour réinitialiser la simulation (exemple)
  // ...
  RCLCPP_INFO(this->get_logger(), "La simulation a été réinitialisée.");
}
