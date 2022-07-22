#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16 ,2);

#define MIN_ANGLE 0
#define MAX_ANGLE 90
#define MIN_ANALOG_VALUE 0
#define MAX_ANALOG_VALUE 1023
int pwmPin = 9;
int potValue;
int angle;
void setup() {
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  for(int min_duty=0;min_duty<=100;min_duty+=10){
    int val = map(min_duty, 0, 100, 0, 255);
    analogWrite(pwmPin, val);
    lcd.setCursor(0,0);
    lcd.print("Duty Cycle: ");
    lcd.setCursor(12,0);
    lcd.print(min_duty);
    potValue = analogRead(A0);
    angle = map(potValue, MIN_ANALOG_VALUE, MAX_ANALOG_VALUE, MIN_ANGLE, MAX_ANGLE);
    lcd.setCursor(0,1);
    lcd.print("Angle: ");
    lcd.setCursor(7,1);
    lcd.print(angle);
    delay(5000);
    lcd.clear(); 
  }
  

}
