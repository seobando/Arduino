#include "const.cpp"
#include "client/externalMachine.cpp"
#include "controllers/traffic.cpp"

void main(){
    
    char traffic_state = getMessage();
    controlTraffic(traffic_state, PIN_LIGHTS_1, PIN_LIGHTS_2) 

}