
void setOutput() {
  if (valueReceived) {
    int commandReceived = findInArray(currentResult);
    writeOutput(commandReceived);
  }
}

void writeOutput(int commandReceived) {
  switch (commandReceived) {
    case TURN_LIGHT_ON:
      if (SERIAL_DEBUG)Serial.println("LIGHTING TURNED ON !");
      digitalWrite(RELAY, HIGH);
      dimmer(TURN_OFF_NOW);
      break;
    case TURN_LIGHT_OFF:
      if (!dimmerActive) {
        if (SERIAL_DEBUG)Serial.println("LIGHTING TURNED OFF !");
        digitalWrite(RELAY, LOW);
      } else {
        dimmer(TURN_LIGHT_OFF);
      }
      break;
    case INCREASE_LIGHT:
      dimmer(INCREASE_LIGHT);
      break;
    case TIMER_ON:
      if (!timerActive){
        zeroTime = millis();
        timerActive=true;
      }
      if (SERIAL_DEBUG)Serial.println("LIGHTING TIMER ON !");      
      break;
  }
}

void dimmer(int control) {
  switch (control) {
    case INCREASE_LIGHT:
      dimmerActive = true;
      if (SERIAL_DEBUG)Serial.println("LIGHTING TURNED ON WITH STEPS !");
      analogWrite(PWM_OUTPUT_A, lastStep);
      lastStep += DIMMER_STEPS;
      //      for (int i = 0; i < 255; i += DIMMER_STEPS) {
      break;
    case TURN_LIGHT_OFF:
      dimmerActive = false;
      if (SERIAL_DEBUG)Serial.println("LIGHTING TURNED OFF SLOWLY!");
      for (int i = lastStep; i > 0; --i) {
        if (SERIAL_DEBUG)Serial.println(i);
        delay(10);
        analogWrite(PWM_OUTPUT_A, i);
        lastStep = 0;
      }
      break;
    case TURN_OFF_NOW:
      if (SERIAL_DEBUG)Serial.println("LIGHTING TURNED OFF NOW!");
      dimmerActive = false;
      lastStep = 0;
      analogWrite(PWM_OUTPUT_A, 0);
      break;
  }
}
