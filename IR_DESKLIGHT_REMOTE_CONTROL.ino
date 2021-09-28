#include "Definitions.h"

#include <IRremote.h>

IRrecv irSource(IR_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irSource.enableIRIn();
  pinMode(PWM_OUTPUT_A, OUTPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
}

void loop() {
  checkIR();
  setOutput();
  checkTimer();
}
