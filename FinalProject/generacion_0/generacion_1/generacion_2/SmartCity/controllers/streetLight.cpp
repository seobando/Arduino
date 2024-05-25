void controlStreetLight(int pin, double threshold){

    double light_measurement = measureLight(pin);

    if(light_measurement < threshold){
        Serial.println("Turning on Streets Lights");
    }else{
        Serial.println("Trunning off Streets Lights");
    }

}

