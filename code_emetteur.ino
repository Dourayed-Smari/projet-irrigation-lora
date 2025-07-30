#include <SPI.h>
#include <LoRa.h>

const int pinCapteur = 34;  // GPIO où est branché AOUT du capteur

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Initialisation LoRa émetteur...");

  // Initialise LoRa
  LoRa.setPins(5, 14, 26);  // NSS, RESET, DIO0
  if (!LoRa.begin(868E6)) {
    Serial.println("Échec de démarrage LoRa !");
    while (1);
  }
  Serial.println("LoRa OK !");
}

void loop() {
  int valeur = analogRead(pinCapteur);
  Serial.print("Valeur humidité : ");
  Serial.println(valeur);

  // Envoi LoRa
  LoRa.beginPacket();
  LoRa.print(valeur);
  LoRa.endPacket();

  delay(3000); // 1 envoi toutes les 3 secondes
}

