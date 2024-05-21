#include "utils/config.h"
#include "utils/const.cpp"
#include "components/testActuators.cpp"

void test(){

  //Test Actuators
  Serial.println("Test TrafficLight 1");
  testChangeTrafficLightStateByLightColor(PIN_LIGHTS_1);
  Serial.println("Test TrafficLight 2");
  testChangeTrafficLightStateByLightColor(PIN_LIGHTS_2);

  //Test Controllers
  /*
  Serial.println("Test Control TrafficLights");
  testControlTrafficLights(PIN_LIGHTS_1, PIN_LIGHTS_2);
  Serial.println("Test Control Traffic");
  testControlTraffic(PIN_LIGHTS_1, PIN_LIGHTS_2);
  */
}

/*
void main(){
    
    char traffic_state = getMessage();
    controlTraffic(traffic_state, PIN_LIGHTS_1, PIN_LIGHTS_2) 

}*/

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  //Pin config
  pinMode(P1, INPUT); //Traffic light 1 button as Input
  pinMode(P2, INPUT); //Traffic light 2 button as Input
  pinMode(CNY1, INPUT); //Infrared sensor 1 in traffic light 1 as Input
  pinMode(CNY2, INPUT); //Infrared sensor 2 in traffic light 1 as Input
  pinMode(CNY3, INPUT); //Infrared sensor 3 in traffic light 1 as Input
  pinMode(CNY4, INPUT); //Infrared sensor 4 in traffic light 2 as Input
  pinMode(CNY5, INPUT); //Infrared sensor 5 in traffic light 2 as Input
  pinMode(CNY6, INPUT); //Infrared sensor 6 in traffic light 2 as Input

  pinMode(TRAFFIC_LIGHT_1_RED, OUTPUT);     // Red traffic light 1 as Output
  pinMode(TRAFFIC_LIGHT_1_YELLOW, OUTPUT);  // Yellow traffic light 1 as Output
  pinMode(TRAFFIC_LIGHT_1_GREEN, OUTPUT);   // Green traffic light 1 as Output
  pinMode(TRAFFIC_LIGHT_2_RED, OUTPUT);     // Red traffic light 2 as Output
  pinMode(TRAFFIC_LIGHT_2_YELLOW, OUTPUT);  // Yellow traffic light 2 as Output
  pinMode(TRAFFIC_LIGHT_2_GREEN, OUTPUT);   // Green traffic light 2 as Output

  //Output cleaning
  digitalWrite(TRAFFIC_LIGHT_1_RED, LOW); //Turn Off Red traffic light 1
  digitalWrite(TRAFFIC_LIGHT_1_YELLOW, LOW); //Turn Off Yellow traffic light 1
  digitalWrite(TRAFFIC_LIGHT_1_GREEN, LOW); //Turn Off Green traffic light 1
  digitalWrite(TRAFFIC_LIGHT_2_RED, LOW); //Turn Off Red traffic light 2
  digitalWrite(TRAFFIC_LIGHT_2_YELLOW, LOW); //Turn Off Yellow traffic light 2
  digitalWrite(TRAFFIC_LIGHT_2_GREEN, LOW); //Turn Off Green traffic light 2
}

void loop() {

  // Run tests
  test();

  // Run main
  //main();


}
