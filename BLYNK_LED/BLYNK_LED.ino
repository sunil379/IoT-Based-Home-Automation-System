#define BLYNK_TEMPLATE_ID "TMPL3QC7nGLAs"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "k75Mzan-lMa3Ql6VACEF1C6e42DSTnnR"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

#define LED 2

char auth[] = BLYNK_AUTH_TOKEN;

BLYNK_WRITE(V0){
  int value = param.asInt();
  if (value) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED,LOW );
  }
}

void setup() {
  // put your setup code here, to run once:
  Blynk.begin(auth);

  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
