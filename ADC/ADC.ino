#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.home();
 lcd.setCursor(0, 0);
 lcd.print("ADC test");
}

void loop() {
  // put your main code here, to run repeatedly:
      String ADC_VAL;

      
      ADC_VAL = String (analogRead(A0));
      lcd.setCursor(0,1);
      lcd.print(ADC_VAL);
      delay(1000);
      lcd.clear();
}
