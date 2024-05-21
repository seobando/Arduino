void testControlTraffic(int pin_lights_1[], int pin_lights_2[]) {

  int traffic_states[] = { 1, 2, 3, 4 };

  for (int traffic_state : traffic_states) {
    controlTraffic(traffic_state, pin_lights_1, pin_lights_2);
  }
}