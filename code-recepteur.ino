#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Initialisation LoRa récepteur...");

  // Initialise LoRa
  LoRa.setPins(5, 14, 26);  // NSS, RESET, DIO0
  if (!LoRa.begin(868E6)) {
    Serial.println("Échec de démarrage LoRa !");
    while (1);
  }
  Serial.println("LoRa OK !");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Reçu : ");
    while (LoRa.available()) {
      String msg = LoRa.readString();
      Serial.println(msg);
    }
  }
}
