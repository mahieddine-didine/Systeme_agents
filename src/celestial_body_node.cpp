#include "mas_solarsystem/celestial_body.h"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto celestial_body = std::make_shared<CelestialBody>();
  rclcpp::spin(celestial_body);
  rclcpp::shutdown();
  return 0;
}
