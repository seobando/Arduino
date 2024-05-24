#include <ArduinoHttpClient.h>
#include "wifiConnection.cpp"

// Constantes
const unsigned long postingInterval = 2 * 1000; // Intervalo mínmo para el envio de datos 2*1000 ms
const unsigned int sensorCount = 3;             // Numero de datos a enviar

// Variables
char* host = "isa.requestcatcher.com"; // No incluir el https://
char* path = "/post";                  // Path
int   port = 80;                       // Puerto

WiFiClient wifi;
HttpClient client = HttpClient(wifi, host, port);

String response;
int statusCode = 0;

void POST_send(int sensorCount, char* sensorNames[], float values[]) {
  String contentType = "application/json";
  String postData = "";
  String request = String(path) + "?";
  for (int idx = 0; idx < sensorCount; idx++) {
    if (idx != 0) request += "&";
    request += sensorNames[idx];
    request += "=";
    request += values[idx];
  }
  client.post(request, contentType, postData);
  statusCode = client.responseStatusCode();
  response = client.responseBody();
  Serial.print("status-code: ");
  Serial.println(statusCode);
}

char* nameArray[] = {"temperature", "humidity", "battery"}; // Nombres de las variables en la nube
float sensorValues[sensorCount];        // Vector de valores
unsigned long lastConnectionTime = 0;   // Marca temporal para el ultimo envio de datos

void POST(float T, float H, float B) {
  sensorValues[0] = T;
  sensorValues[1] = H;
  sensorValues[2] = B;
  if ((millis() - lastConnectionTime) > postingInterval)
  {
    Serial.print("[SEND]\tEnviando datos > ");
    POST_send(sensorCount, nameArray, sensorValues);  // REST call
    lastConnectionTime = millis();  // Actualizamos la marca temporal
  }
}
