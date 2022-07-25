#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16 ,2);

#define MIN_ANGLE 0
#define MAX_ANGLE 90
#define MIN_ANALOG_VALUE 0
#define MAX_ANALOG_VALUE 262

int potValue;
int angle;

void analogWriteSAH_Init( void )
{

  TCCR1B = (0 << ICNC1) | (0 << ICES1) | (0 << WGM13) | (0 << WGM12) | (0 << CS12) | (0 << CS11) | (0 << CS10);
  
  // Set the timer to mode 14...
  //
  // Mode  WGM13  WGM12  WGM11  WGM10  Timer/Counter Mode of Operation  TOP   Update of OCR1x at TOV1  Flag Set on
  //              CTC1   PWM11  PWM10
  // ----  -----  -----  -----  -----  -------------------------------  ----  -----------------------  -----------
  // 14    1      1      1      0      Fast PWM                         ICR1  BOTTOM                   TOP
  
  // Set output on Channel A to...
  //
  // COM1A1  COM1A0  Description
  // ------  ------  -----------------------------------------------------------
  // 1       0       Clear OC1A/OC1B on Compare Match (Set output to low level).
  
  TCCR1A = 
      (1 << COM1A1) | (0 << COM1A0) |   // COM1A1, COM1A0 = 1, 0
      (0 << COM1B1) | (0 << COM1B0) | 
      (1 << WGM11) | (0 << WGM10);      // WGM11, WGM10 = 1, 0
  
  // Set TOP to...
  //
  // fclk_I/O = 16000000
  // N        = 1
  // TOP      = 799
  //
  // fOCnxPWM = fclk_I/O / (N * (1 + TOP))
  // fOCnxPWM = 16000000 / (1 * (1 + 799))
  // fOCnxPWM = 16000000 / 800
  // fOCnxPWM = 20000

  ICR1 = 799;
  
  // Ensure the first slope is complete

  TCNT1 = 0;
  
  // Ensure Channel B is irrelevant
  
  OCR1B = 0;
  
  // Ensure Channel A starts at zero / off
  
  OCR1A = 0;
  
  
  TIMSK1 = (0 << ICIE1) | (0 << OCIE1B) | (0 << OCIE1A) | (0 << TOIE1);

  // Ensure the Channel A pin is configured for output
  DDRB |= (1 << DDB1);

  // Start the timer...
  //
  // CS12  CS11  CS10  Description
  // ----  ----  ----  ------------------------
  // 0     0     1     clkI/O/1 (No prescaling)

  TCCR1B = 
      (0 << ICNC1) | (0 << ICES1) | 
      (1 << WGM13) | (1 << WGM12) |              // WGM13, WGM12 = 1, 1
      (0 << CS12) | (0 << CS11) | (1 << CS10);
}

void analogWriteSAH( uint16_t value )
{
  if ( (value >= 0) && (value < 800) )
  {
    OCR1A = value;
  }
}

void setup() {
  analogWriteSAH_Init();
  lcd.init();
  lcd.backlight();

}

void loop() {
 for(int min_duty=16;min_duty<=100;min_duty+=5){
    int val = map(min_duty, 0, 110, 0, 799);
    analogWriteSAH(val);
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
