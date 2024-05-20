#include "const.cpp"
#include "display"
#include "components/testActuators.cpp"
#include "controllers/testControlTraffic.cpp"

void test(){

  //Test Display
  displayMessage("SmartCity ON");

  //Test Actuators
  Serial.println("Test TrafficLight 1");
  testChangeTrafficLightColorByLightColor(PIN_LIGHTS_1);
  Serial.println("Test TrafficLight 2");
  testChangeTrafficLightColorByLightColor(PIN_LIGHTS_2);

  //Test Controllers
  Serial.println("Test Control TrafficLights");
  testControlTrafficLights(PIN_LIGHTS_1, PIN_LIGHTS_2);
  Serial.println("Test Control Traffic");
  testControlTraffic(PIN_LIGHTS_1, PIN_LIGHTS_2);

}


