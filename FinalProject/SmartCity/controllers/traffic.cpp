void controlTraffic(char traffic_state, int pin_lights_1[], int pin_lights_2[]) {

  int delay_between_lights = 10;
  in time_base = 1000;

  switch (traffic_state) {
    case 'HH':
      Serial.println("Traffic state High-High");
      int delay_between_traffic_lights = 6 * time_base;
      controlTrafficLights(delay_between_traffic_lights, delay_between_lights, pin_lights_1, pin_lights_2) break;
    case 'HL':
      Serial.println("Traffic state High-Low");
      changeTrafficLightStateByPinValue(pin_lights[1], state);
      int delay_between_traffic_lights = 5 * time_base;
      controlTrafficLights(delay_between_traffic_lights, delay_between_lights, pin_lights_1, pin_lights_2) break;
    case 'LL':
      Serial.println("Traffic state Low-Low");
      int delay_between_traffic_lights = 2 * time_base;
      controlTrafficLights(delay_between_traffic_lights, delay_between_lights, pin_lights_2, pin_lights_1) break;
    case 'LH':
      Serial.println("Traffic state Low-High");
      int delay_between_traffic_lights = 3 * time_base;
      controlTrafficLights(delay_between_traffic_lights, delay_between_lights, pin_lights_2, pin_lights_1) break;
  }
}