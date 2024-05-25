#include <Arduino.h>
#include <math.h> //Mathematics library for pow function (CO2 computation)

double measureLight(int pin) {
  double light_measurement = analogRead(pin);
  Serial.println("Light pin: " + String(pin));
  Serial.println("Light measurement: " + String(light_measurement));
  return light_measurement;
}

bool validateProximity(int pin) {

  bool is_anything_there = false;

  if (digitalRead(pin) == HIGH) {
    Serial.println("P1: ON");
    delay(300);                         //Debouncing for buttons using delay of 300 ms
    while (digitalRead(P1) == HIGH) {}  //Debouncing
  }

  return is_anything_there;
}

bool validateButtons(int pin) {

  bool is_button_on = false;
  if (digitalRead(pin) == HIGH) {
    Serial.println("P1: ON");
    is_button_on = true;
    delay(300);     //Debouncing for buttons using delay of 300 ms
    while (digitalRead(P1) == HIGH) {}  //Debouncing
  }

  return is_button_on;
}


double measureCO2(int pin) {

  //->CO2
  const float DC_GAIN = 8.5;  //define the DC gain of amplifier CO2 sensor
  //const float ZERO_POINT_VOLTAGE = 0.4329; //define the output of the sensor in volts when the concentration of CO2 is 400PPM
  const float ZERO_POINT_VOLTAGE = 0.265;                                                     //define the output of the sensor in volts when the concentration of CO2 is 400PPM
  const float REACTION_VOLTAGE = 0.059;                                                       //define the “voltage drop” of the sensor when move the sensor from air into 1000ppm CO2
  const float CO2Curve[3] = { 2.602, ZERO_POINT_VOLTAGE, (REACTION_VOLTAGE / (2.602 - 3)) };  //Line curve with 2 points

  //Variable definitions
  char comm = '\0';  //Command to test an actuator or sensor
  float volts = 0;   //Variable to store current voltage from CO2 sensor
  float co2 = 0;     //Variable to store CO2 value

  volts = analogRead(pin) * 5.0 / 1023.0;  //Convert CO2 ADC to volts
  if (volts / DC_GAIN >= ZERO_POINT_VOLTAGE) {
    Serial.println("Error reading CO2");
  } else {
    co2 = pow(10, ((volts / DC_GAIN) - CO2Curve[1]) / CO2Curve[2] + CO2Curve[0]);
    Serial.println("CO2: " + String(co2));
  }

  return co2;
}
