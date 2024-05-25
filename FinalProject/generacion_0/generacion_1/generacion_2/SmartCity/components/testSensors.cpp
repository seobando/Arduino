void testChangeTrafficLightStateByLightColor(int pin_light_sensors[], int pin_buttons[], int co2, int pin_proximity_sensors[]) {
 
  /*

  LDR1 0 //LDR Light sensor from traffic light 1 connected in pin A0

  LDR2 1  //LDR Light sensor from traffic light 2 connected in pin A1 

  */

  for (int i = 0; i < sizeof(pin_light_sensors) / sizeof(pin_light_sensors[0]); i++) {

    double light_measure = measureLight(pin_light_sensors[i]);

      Serial.println("Checking light measure: " + String(light_measure));

  }
 
  /*

  P1 37  //Traffic light 1 button connected in pin 37

  P2 36  //Traffic light 2 button connected in pin 36    

  */

  for (int i = 0; i < sizeof(pin_buttons) / sizeof(pin_buttons[0]); i++) {

    bool is_button_on = validateButtons(pin_buttons[i]);

      Serial.println("Checking buttons: " + String(is_button_on));

  }
 
  //CO2 sensor connected in pin 3

  double co2_reading = measureCO2(co2);

    Serial.println("Checking CO2: " + String(co2_reading));
 
  /*

  CNY1 35 //Infrared sensor 1 in traffic light 1 connected in pin 35

  CNY2 34 //Infrared sensor 2 in traffic light 1 connected in pin 34

  CNY3 33 //Infrared sensor 3 in traffic light 1 connected in pin 33

  CNY4 32 //Infrared sensor 4 in traffic light 2 connected in pin 32

  CNY5 31 //Infrared sensor 5 in traffic light 2 connected in pin 31

  CNY6 30 //Infrared sensor 6 in traffic light 2 connected in pin 30

*/

  for (int i = 0; i < sizeof(pin_proximity_sensors) / sizeof(pin_proximity_sensors[0]); i++) {

    bool is_anything_there = validateProximity(pin_proximity_sensors[i]);

      Serial.println("Checking sensor proximity: " + String(is_anything_there));

  }

}
