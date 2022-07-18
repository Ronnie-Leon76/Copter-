#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16 ,2);

#include <Servo.h>

Servo ESC;     

 
int pwmPin = 9;
int value = 0;
int potValue;

#define IN_ANALOG_READ_VAL_MIN 0
#define IN_ANALOG_READ_VAL_MAX 264
#define IN_ANGLE_MIN 0
#define IN_ANGLE_MAX 90


int read_angle(int potValue){
  int angle = map(potValue, IN_ANALOG_READ_VAL_MIN, IN_ANALOG_READ_VAL_MAX, IN_ANGLE_MIN, IN_ANGLE_MAX);
  return angle;
}

int get_duty_cycle(int value){
  int duty_cycle = map(value, 0, 1023, 0, 5);
  return duty_cycle/5*100;
}


void setup() {
  ESC.attach(pwmPin,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
 
}

void loop() {
   lcd.setCursor(0,0);
   lcd.print("Hello World!");
   lcd.clear();
   do{
    int val = map(value, 0, 1023, 0, 180);
    ESC.write(val);
    delay(2000);
    value+=10;
    int duty_cycle = get_duty_cycle(value);
    int angle;
    if(duty_cycle == 20){
        potValue = analogRead(A0);
        Serial.print(potValue);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("20% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print("20%");
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    }else if(duty_cycle == 40){
        potValue = analogRead(A0);
        Serial.print(potValue);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("40% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print("30%");
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 50){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("50% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 60){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("60% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 70){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("70% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 80){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("80% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 90){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print("90% duty cycle");
        lcd.setCursor(1,0);
        lcd.print(angle);
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else if(duty_cycle == 100){
        potValue = analogRead(A0);
        angle = read_angle(potValue);
        lcd.setCursor(0,0);
        lcd.print(angle);
        Serial.print(angle);
        Serial.print("\n");
        delay(5000);
        lcd.clear();
    } else {
        potValue = analogRead(A0);
        lcd.setCursor(0,0);
        lcd.print(potValue);
        Serial.print(potValue);
        Serial.print("\n");
        angle = read_angle(potValue);
    }
    
    
  }
  while(value<=1023);

  
}
