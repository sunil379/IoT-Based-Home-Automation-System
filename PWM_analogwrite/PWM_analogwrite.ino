#define LED 3
#define LDR_SENSOR A0
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

unsigned int ldr_val;

void loop() {
  // put your main code here, to run repeatedly:
  ldr_val = analogRead(A0);
  ldr_val = (1023 - ldr_val)/4;
  analogWrite(LED, ldr_val);
  delay(100);
  
}
