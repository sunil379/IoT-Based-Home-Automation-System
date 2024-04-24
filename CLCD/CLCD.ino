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
 lcd.print("Sunil Dewangan");
 lcd.setCursor(4, 1);
 lcd.print("emertxe");
}

void loop() {
  // put your main code here, to run repeatedly:

}
