#include<Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;
  Serial.println("Skanowanie...");
  nDevices = 0;
  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Znaleziono urzadzenie I2C na adresie 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error==4) {
      Serial.print("Nieznany blad na adresie 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    } 
  }
  if (nDevices == 0)
    Serial.println("Brak urzadzen I2C\n");
  else
    Serial.println("Gotowe\n");
  delay(5000);
}
