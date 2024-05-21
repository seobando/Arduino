/*
void controlTrafficLights(
  int delay_between_traffic_lights,
  int delay_between_lights,
  int pin_lights_1[],
  int pin_lights_2[]) {

  int colors_positions = 2;

  for (int i = 0; i <= colors_positions; i++) {
    Serial.println("i " + String(i));
    char pin_lights_1_color = COLORS[i];
    char pin_lights_2_color = COLORS[colors_positions - i];

    changeTrafficLightStateByLightColor(pin_lights_1_color, 1, pin_lights_1);
    changeTrafficLightStateByLightColor(pin_lights_2_color, 1, pin_lights_2);

    if (COLORS[i] == 'G') {
      delay(delay_between_traffic_lights);
    } else {
      delay(delay_between_lights);
    }

    changeTrafficLightStateByLightColor(pin_lights_1_color, 0, pin_lights_1);
    changeTrafficLightStateByLightColor(pin_lights_2_color, 0, pin_lights_2);
  };
}*/