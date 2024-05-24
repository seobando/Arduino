#include <SPI.h>
#include <WiFi101.h>

// Variables para la conexión WiFi
char ssid[] = "rayido.com";     // Network SSID (name)
char pass[] = "isa20232";       // Network password
int status = WL_IDLE_STATUS;    // Network status

void printWifiStatus() {
  // Muestra el nombre de la red WiFi
  Serial.print("[WIFI]\tConectado a SSID: ");
  Serial.println(WiFi.SSID());

  // Muestra la dirección IP
  IPAddress ip = WiFi.localIP();
  Serial.print("[WIFI]\tDirección IP: ");
  Serial.println(ip);

  // Muestra la intensidad de señal:
  long rssi = WiFi.RSSI();
  Serial.print("[WIFI]\tIntensidad de señal (RSSI): ");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void WiFiInit() {
  // Le damos tiempo al shield WiFi de iniciar:
  delay(1000);

  // Verificamos la presencia del shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("[WIFI]\tShield not present");
    while (true); // No continuamos
  }

  String fv = WiFi.firmwareVersion();
  if (fv <= "1.1.0" )
    Serial.println("[WIFI]\tPor favor actualizar el firmware");

  // Intentando conectarse al WiFi:
  while (status != WL_CONNECTED) {
    Serial.print("[WIFI]\tIntento de connexión al SSID: ");
    Serial.println(ssid);
    // Conexión a una red por WPA/WPA2.
    // Cambiar la siguiente linea si usa un WIFI abierto o red WEP:
    status = WiFi.begin(ssid, pass);

    // Esperando 1 segundo para conexión:
    delay(1000);
  }
  // Estamos conectados, mostramos la información de la conexión:
  printWifiStatus();
}