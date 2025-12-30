/*
   Geiger Counter - PPS only
   Arduino Nano
   Affichage du nombre d'impulsions sur la dernière seconde (PPS)
*/

#define GEIGER_PIN 2   // D2 = INT0 sur Arduino Nano

volatile unsigned long pulseCount = 0;

unsigned long lastSecond = 0;
unsigned long pps = 0;

void geigerISR() {
  pulseCount++;   // Une impulsion détectée
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Geiger Counter - PPS mode");

  pinMode(GEIGER_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(GEIGER_PIN), geigerISR, FALLING);

  lastSecond = millis();
}

void loop() {

  if (millis() - lastSecond >= 1000) {

    noInterrupts();
    pps = pulseCount;
    pulseCount = 0;
    interrupts();

    // Affichage PPS
    Serial.print("PPS = ");
    Serial.println(pps);

    lastSecond += 1000;
  }
}
