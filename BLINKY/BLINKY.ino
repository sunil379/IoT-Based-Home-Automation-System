
#define LED_BUILTIN
void setup() {
  // put your setup code here, to run once:
    pinMode(LED_BUILTIN , OUTPUT);
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN , HIGH);
    delayMicroseconds(500);
    digitalWrite(LED_BUILTIN , LOW);
    delayMicroseconds(500);
    
}
