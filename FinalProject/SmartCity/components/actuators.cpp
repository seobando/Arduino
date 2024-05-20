void changeTrafficLightStateByPinValue(int pin, int state) {
  if (state) {
    digitalWrite(pin, HIGH);
    Serial.println("Turning ON " + String(pin));
  } else {
    Serial.println("Turning OFF " + String(pin));
    digitalWrite(pin, LOW);
  }
}

void changeTrafficLightStateByLightColor(char light_color, int state, int pin_lights[]) {
  switch (light_color) {
    case 'R':
      Serial.println("changing to light color red");
      changeTrafficLightStateByPinValue(pin_lights[0], state);
      break;
    case 'Y':
      Serial.println("changing to light color yellow");
      changeTrafficLightStateByPinValue(pin_lights[1], state);
      break;
    case 'G':
      Serial.println("changing to light color green");
      changeTrafficLightStateByPinValue(pin_lights[2], state);
      break;
  }
}