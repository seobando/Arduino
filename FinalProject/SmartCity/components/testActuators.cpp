void testChangeTrafficLightStateByLightColor(int pin_lights[]) {
  int delay_between_lights = 2000;
  for (char color : COLORS) {
    changeTrafficLightStateByLightColor(color, 1, pin_lights);
    delay(delay_between_lights);
    changeTrafficLightStateByLightColor(color, 0, pin_lights);
    delay(delay_between_lights);
  };
}