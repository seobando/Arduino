#include <Arduino.h>

void controlTraffic(int traffic_state, int pin_lights_1[], int pin_lights_2[]) {

  int delay_between_lights = 10;
  int time_base = 1000;

  switch (traffic_state) {
    case 1:
      Serial.println("Traffic state High-High");
      controlTrafficLights(6 * time_base, delay_between_lights, pin_lights_1, pin_lights_2);
      break;
    case 2:
      Serial.println("Traffic state High-Low");
      controlTrafficLights(5 * time_base, delay_between_lights, pin_lights_1, pin_lights_2);
      break;
    case 3:
      Serial.println("Traffic state Low-Low");
      controlTrafficLights(2 * time_base, delay_between_lights, pin_lights_2, pin_lights_1);
      break;
    case 4:
      Serial.println("Traffic state Low-High");
      controlTrafficLights(3 * time_base, delay_between_lights, pin_lights_2, pin_lights_1);
      break;
  }
}