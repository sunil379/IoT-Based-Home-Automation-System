
#define INLET_VALUE  0x00
#define OUTLET_VALUE 0x01

#define HIGH_FLOAT 0x10
#define LOW_FLOAT 0x10

#define VOLUME    0X30

#define ENABLE    0x01
#define DISABLE   0x00

#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 10,2);
unsigned char Value_H,Value_L;
unsigned int volume;
unsigned char volumeL, volumeH;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.home();
 lcd.setCursor(0, 0);
 lcd.print("Connect Srtank");
 Serial.write(0xFF);
 Serial.write(0xFF);
 Serial.write(0xFF);
}
  
void volume_water(void){
    Serial.write(VOLUME);
    while (!Serial.available());
    volumeH = Serial.read();
    while (!Serial.available());
    volumeL = Serial.read();
    volume = volumeH<<8 | volumeL;
 lcd.setCursor(0, 1);
 lcd.print("Vol");
 lcd.print(volume);
 lcd.print("ltr");
}

 void filling_tank(void){
    Serial.write(INLET_VALUE);
    Serial.write(ENABLE);
    
    Serial.write(OUTLET_VALUE);
    Serial.write(DISABLE);

    lcd.setCursor(0, 0);
    lcd.print("Filling");

    
    do {
    Serial.write(HIGH_FLOAT);
    while (!Serial.available());
    Value_H = Serial.read();
    volume_water();
  }while (Value_H == 0);
}

void start_emptying(void){
    Serial.write(OUTLET_VALUE);
    Serial.write(ENABLE);
    
    Serial.write(INLET_VALUE);
    Serial.write(DISABLE);

    lcd.setCursor(0, 0);
    lcd.print("Empting");

     do {
    Serial.write(LOW_FLOAT);
    while (!Serial.available());
    Value_L = Serial.read();
    volume_water();
    }while (Value_L == 0);
  }

void loop() {
  // put your main code here, to run repeatedly:
    filling_tank();
    start_emptying();
}
