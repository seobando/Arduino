#include "generacion_1/generacion_2/SmartCity/utils/config.h"
#include "generacion_1/generacion_2/SmartCity/utils/const.cpp"
// Components
#include "generacion_1/generacion_2/SmartCity/components/actuators.cpp"
#include "generacion_1/generacion_2/SmartCity/components/testActuators.cpp"
#include "generacion_1/generacion_2/SmartCity/components/sensors.cpp"
#include "generacion_1/generacion_2/SmartCity/components/testSensors.cpp"
// Controllers
#include "generacion_1/generacion_2/SmartCity/controllers/trafficLights.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/testTrafficLights.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/traffic.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/testTraffic.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/alerts.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/testAlerts.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/streetLight.cpp"
#include "generacion_1/generacion_2/SmartCity/controllers/testStreetLight.cpp"
// Libraries
#include <Wire.h>               //Library required for I2C comms (LCD)
#include <LiquidCrystal_I2C.h>  //Library for LCD display via I2C
#include <math.h>               //Mathematics library for pow function (CO2 computation)
 
//Library definitions
LiquidCrystal_I2C lcd(0x27, 16, 4);  //Set the LCD address to 0x27 for a 16 chars and 4 line display
 
void displayMessage(String message, int delay_time) {
  Serial.println("Display shows: " + String(message));
  lcd.setCursor(0, 0);
  lcd.print(message);
  delay(delay_time);
  lcd.clear();
}
 
void test() {
 
  //Test Display
  Serial.println("Start tests");
  displayMessage("Start tests", 2000);
 
  //Test Actuators
  Serial.println("Testing TrafficLight 1");
  displayMessage("Testing TrafficLight 1", 2000);
  testChangeTrafficLightStateByLightColor(PIN_LIGHTS_1);
 
  Serial.println("Testing TrafficLight 2");
  displayMessage("Testing TrafficLight 2", 2000);
  testChangeTrafficLightStateByLightColor(PIN_LIGHTS_2);
 
  //Test Sensors
  Serial.println("Testing Sensors");
  displayMessage("Testing Sensors", 2000);

  int pin_light_sensors[] =  {1,2};
  int pin_buttons[] = {37,36};
  int co2= 3;
  int pin_proximity_sensors[] =  {35,34,33,32,31,30};
  testChangeTrafficLightStateByLightColor(pin_light_sensors, pin_buttons, co2, pin_proximity_sensors);
 
  //Test Controllers
  Serial.println("Testing Control TrafficLights");
  displayMessage("Testing Control TrafficLights", 2000);
  testControlTrafficLights(PIN_LIGHTS_1, PIN_LIGHTS_2);
 
  Serial.println("Testing Control Traffic");
  displayMessage("Testing Control Traffic", 2000);
  testControlTraffic(PIN_LIGHTS_1, PIN_LIGHTS_2);
 
  Serial.println("Testing Control alerts");
  displayMessage("Testing Control alerts", 2000);
  testControlAlerts();
 
  Serial.println("Testing Street lights");
  displayMessage("Testing Street lights", 2000);
  testControlStreetLight();
 
  Serial.println("End tests");
  displayMessage("End tests", 2000);
}
 
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
 
  // Wait for serial port to open
  while (!Serial) {
    delay(10);
  }
 
  //Pin config
  pinMode(P1, INPUT);                       //Traffic light 1 button as Input
  pinMode(P2, INPUT);                       //Traffic light 2 button as Input
  pinMode(CNY1, INPUT);                     //Infrared sensor 1 in traffic light 1 as Input
  pinMode(CNY2, INPUT);                     //Infrared sensor 2 in traffic light 1 as Input
  pinMode(CNY3, INPUT);                     //Infrared sensor 3 in traffic light 1 as Input
  pinMode(CNY4, INPUT);                     //Infrared sensor 4 in traffic light 2 as Input
  pinMode(CNY5, INPUT);                     //Infrared sensor 5 in traffic light 2 as Input
  pinMode(CNY6, INPUT);                     //Infrared sensor 6 in traffic light 2 as Input
  pinMode(TRAFFIC_LIGHT_1_RED, OUTPUT);     // Red traffic light 1 as Output
  pinMode(TRAFFIC_LIGHT_1_YELLOW, OUTPUT);  // Yellow traffic light 1 as Output
  pinMode(TRAFFIC_LIGHT_1_GREEN, OUTPUT);   // Green traffic light 1 as Output
  pinMode(TRAFFIC_LIGHT_2_RED, OUTPUT);     // Red traffic light 2 as Output
  pinMode(TRAFFIC_LIGHT_2_YELLOW, OUTPUT);  // Yellow traffic light 2 as Output
  pinMode(TRAFFIC_LIGHT_2_GREEN, OUTPUT);   // Green traffic light 2 as Output
 
  //Output cleaning
  digitalWrite(TRAFFIC_LIGHT_1_RED, LOW);     //Turn Off Red traffic light 1
  digitalWrite(TRAFFIC_LIGHT_1_YELLOW, LOW);  //Turn Off Yellow traffic light 1
  digitalWrite(TRAFFIC_LIGHT_1_GREEN, LOW);   //Turn Off Green traffic light 1
  digitalWrite(TRAFFIC_LIGHT_2_RED, LOW);     //Turn Off Red traffic light 2
  digitalWrite(TRAFFIC_LIGHT_2_YELLOW, LOW);  //Turn Off Yellow traffic light 2
  digitalWrite(TRAFFIC_LIGHT_2_GREEN, LOW);   //Turn Off Green traffic light 2
 
  //Communications
  lcd.init();       //Start communications with LCD display
  lcd.backlight();  //Turn on LCD backlight
 
  // Run tests
  test();
}
 
void loop() {
 
}