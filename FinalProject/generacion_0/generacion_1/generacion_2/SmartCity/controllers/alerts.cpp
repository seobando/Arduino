void controlAlertPolution(double threshold){
    double co2 = measureCO2(pin);

    if(co2 > threshold){
        System.println("Alert! the air polution is higher than " + String(threshold));
    }
}

void controlAlertTrafficJam(){
    
    int pin_proximity_sensors[] = [35,34,33,32,31,30];

    for (int pin_proximity_sensor : pin_proximity_sensors) {
        bool is_anything_there = validateProximity(pin_proximity_sensor);
        if (is_anythin_there){
            System.println("Alert! there is a traffic jam on: " + String(pin_proximity_sensor));
            break;
        }
        
    }
}

void controlAlertTrafficLightStop(){

    int pin_buttons[] = [37,36];

    for (int pin_button : pin_buttons) {
        bool is_button_on = validateButtons(pin_button);
        System.println("Stop: " + String(is_button_on));
        if (is_button_on){

            if(pin_button == 37){
                System.println("Alert! people trying to cross the street of trafficlight 1");
            }else{
                System.println("Alert! people trying to cross the street of trafficlight 2");
            }
        } 
        
  }

}
