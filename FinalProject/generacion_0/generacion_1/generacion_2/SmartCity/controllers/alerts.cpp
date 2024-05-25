
void controlAlertPolution(double threshold){
    double co2 = measureCO2(3);

    if(co2 > threshold){
        Serial.println("Alert! the air polution is higher than " + String(threshold));
    }
}

void controlAlertTrafficJam(){
    bool is_anything_there = false;
    int pin_proximity_sensors[] = {35,34,33,32,31,30};

    for (int pin_proximity_sensor : pin_proximity_sensors) {
        bool is_anything_there = validateProximity(pin_proximity_sensor);
        if (is_anything_there){
            Serial.println("Alert! there is a traffic jam on: " + String(pin_proximity_sensor));
            break;
        }
        
    }
}

void controlAlertTrafficLightStop(){

    int pin_buttons[] = {37,36};

    for (int pin_button : pin_buttons) {
        bool is_button_on = validateButtons(pin_button);
        Serial.println("Stop: " + String(is_button_on));
        if (is_button_on){

            if(pin_button == 37){
                Serial.println("Alert! people trying to cross the street of trafficlight 1");
            }else{
                Serial.println("Alert! people trying to cross the street of trafficlight 2");
            }
        } 
        
  }

}
