#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
int sensorVal;
float voltage;
float temperature;
long interval = 15000;

unsigned long previousTime = 0;

int calculateTemperature() {
  sensorVal = analogRead(sensorPin);
  voltage = (sensorVal/1024.0) * 5.0;
  temperature = (voltage - 0.5) * 100;
  return temperature;
}

void printTemperature() {
  lcd.clear();
  calculateTemperature();
  lcd.setCursor(6, 0);
  lcd.print("The");
  lcd.setCursor(1,1);
  lcd.print("temperature is");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(temperature);
  lcd.setCursor(4, 1);
  lcd.print("Celsius");
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print ("WELCOME");
  lcd.setCursor(2, 1);
  lcd.print("Temperature");
  delay(5000);
  lcd.clear();
  printTemperature();
}

void loop() {
  

  
  unsigned long currentTime = millis();

   
  
  if(currentTime - previousTime > interval){
   printTemperature();
   previousTime = currentTime;
  }
  
}
