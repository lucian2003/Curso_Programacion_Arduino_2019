#define PIN_LDR A1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  
int maximo = 0;
int minimo = 1023;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  
  int sensorValue = analogRead(PIN_LDR);
  
  while (max(maximo,sensorValue) > maximo) {
    maximo = max(maximo,sensorValue);
  }

  while (max(minimo,sensorValue) < minimo) {
    minimo = max(minimo,sensorValue);
  }
  
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print(maximo);
  Serial.print(",");
  Serial.println(minimo);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Max: ");
  lcd.print(maximo);
  lcd.setCursor(0, 1);
  lcd.print("Min:");
  lcd.print(minimo);
  delay(500);
}
