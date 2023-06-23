#ifndef USER_ENV_NODE_H
#define USER_ENV_NODE_H

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/empty.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <map>
#include <string>

class UserEnvNode : public rclcpp::Node
{
public:
  UserEnvNode();

private:
  rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr earth_position_publisher_;
  rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr mars_position_publisher_;
  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr reset_simulation_service_;
  rclcpp::Parameter space_scale_param_;
  rclcpp::Parameter time_scale_param_;
  double space_scale_;
  double time_scale_;

  void publishEarthPosition();
  void publishMarsPosition();
  void resetSimulation();
};

#endif  // USER_ENV_NODE_H
