#include <Arduino.h>

#define ANALOG_PIN A0
#define LED_PIN 2
#define SENSITIVTY 50

int state = LOW;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int analog = analogRead(ANALOG_PIN);
  
  // 0 - 1024
  bool digital = analog > 50;
  digitalWrite(LED_PIN, !digital);

  if (digital != state) 
  {
    state = digital;
    Serial.printf("\n%d: Pin value:", digital); Serial.print(((analog*1000)/1024*3.3)/1000);
  }
}