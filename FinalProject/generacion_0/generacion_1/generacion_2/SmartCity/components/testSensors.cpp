void testChangeTrafficLightStateByLightColor(int pin_light_sensors[], int pin_buttons[], int co2, int pin_proximity_sensors[]) {

  /*
  LDR1 0 //LDR Light sensor from traffic light 1 connected in pin A0
  LDR2 1  //LDR Light sensor from traffic light 2 connected in pin A1 
  */
  for (int pin_light_sensor : pin_light_sensors) {
    double light_measure = measureLight(pin_light_sensor);
    System.println("Checking light measure: " + String(light_measure);
  }

  /*
  P1 37  //Traffic light 1 button connected in pin 37
  P2 36  //Traffic light 2 button connected in pin 36    
  */
  for (int pin_button : pin_buttons) {
    bool is_button_on = validateButtons(pin_button);
    System.println("Checking buttons: " + String(is_button_on);
  }
  
  //CO2 sensor connected in pin A3
  double co2 = measureCO2(co2);
  System.println("Checking CO2: " + String(co2));

  /*
  CNY1 35 //Infrared sensor 1 in traffic light 1 connected in pin 35
  CNY2 34 //Infrared sensor 2 in traffic light 1 connected in pin 34
  CNY3 33 //Infrared sensor 3 in traffic light 1 connected in pin 33
  CNY4 32 //Infrared sensor 4 in traffic light 2 connected in pin 32
  CNY5 31 //Infrared sensor 5 in traffic light 2 connected in pin 31
  CNY6 30 //Infrared sensor 6 in traffic light 2 connected in pin 30
 */
  for (int pin_light_sensor : pin_light_sensors) {
    bool is_anything_there = validateProximity(pin);
    System.println("Checking sensor proximity: " + String(is_anything_there));
  }

}