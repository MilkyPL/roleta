#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Swiatlo");
}

void loop() {
  int sensorValue = analogRead(A0);
  float light = sensorValue * (100.0 / 1023.0);
  lcd.setCursor(0,1);
  lcd.print(light);
  delay(500);
}
