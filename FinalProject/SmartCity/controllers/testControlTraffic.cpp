#include "traffic.cpp"

void testControlTraffic(int pin_lights_1[], int pin_lights_2[]) {

  char traffic_states[] = { "HH", "HL", "LH", "LL" };

  for (char traffic_state : traffic_states) {
    controlTraffic(traffic_state, pin_lights_1, pin_lights_2);
  }
}