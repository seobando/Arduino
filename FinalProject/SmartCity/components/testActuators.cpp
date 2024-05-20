#include "actuators.cpp"

void testChangeTrafficLightColorByLightColor(int pin_lights[]) {
  int delay_between_lights = 2000;
  for (char color : COLORS) {
    changeTrafficLightColorByLightColor(color, 1, pin_lights);
    delay(delay_between_lights);
    changeTrafficLightColorByLightColor(color, 0, pin_lights);
    delay(delay_between_lights);
  };
}