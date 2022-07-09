#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16 ,2);
/**
 * Copter Propeller 
 * Operations done:
 * 1. Self calibration step during initialization that allows the system to automatically find the vertical position
 * i.e ensure the PWM duty cycle is marked when motor shaft is at 0 degrees.
 * Also make sure motor driver runs clockwise
 * 2. Include Servo Library because we need a 50Hz PWM signal.
 * 3. Create an object of the Servo class
 * 4. Declare pwmPin variable and assign PWM pin 9 to it
 * 1. 
**/

#include <Servo.h>
#define IN_ANALOG_READ_VAL_MIN 0
#define IN_ANALOG_READ_VAL_MAX 1023
#define IN_ANGLE_MIN 0
#define IN_ANGLE_MAX 90

Servo ESC;     

int potValue;  
int pwmPin = 9;
int value = 0;

int read_angle(int potValue){
  int angle = map(potValue, IN_ANALOG_READ_VAL_MIN, IN_ANALOG_READ_VAL_MAX, IN_ANGLE_MIN, IN_ANGLE_MAX);
  return angle;
}

int get_duty_cycle(int value){
  int duty_cycle = map(value, 0, 1023, 0, 5);
  return duty_cycle/5*100;
}

void setup() {
  lcd.init();
  lcd.backlight();
  ESC.attach(pwmPin,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
}

void loop() {
  do{
    ESC.write(value);
    value+=10;
    int duty_cycle = get_duty_cycle(value);
    int angle;
    if(duty_cycle == 20){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    }else if(duty_cycle == 40){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 50){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 60){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 70){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 80){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 90){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 100){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        delay(5000);
        lcd.clear();
    } else {
      Serial.println("Invalid Duty Cycle");
    }
    
    
  }
  while(value<=1023);

}
