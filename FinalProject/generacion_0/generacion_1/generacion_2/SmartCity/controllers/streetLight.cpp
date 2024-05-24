void controlStreetLight(int pin, double threshold){

    double light_measurement = measureLight(pin);

    if(light_measurement < threshold){
        System.println("Turning on Streets Lights");
    }else{
        System.println("Trunning off Streets Lights");
    }

}

