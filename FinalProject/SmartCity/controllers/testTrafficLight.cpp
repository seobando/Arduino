#include "trafficLight.cpp"

void testControlTrafficLights(int pin_lights_1[], int pin_lights_2[]) {

  int delay_between_traffic_lights = 10000;
  int delay_between_lights = 2000;

  controlTrafficLights(delay_between_traffic_lights, delay_between_lights, pin_lights_1, pin_lights_2);
}