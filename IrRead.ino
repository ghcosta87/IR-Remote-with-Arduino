
void checkIR() {
  if (irSource.decode(&results)) {
    currentResult = results.value;
    if (SERIAL_DEBUG)Serial.println(currentResult, HEX);
    irSource.resume();
    valueReceived = true;
  } else {
    valueReceived = false;
  }
}

int findInArray(long int dataToFind) {
  int arrayLength = sizeof(IR_ON) / sizeof(IR_ON[0]);
  int i;
  for (i = 0; i < arrayLength; i++) {
    if (IR_ON[i] == dataToFind)return TURN_LIGHT_ON;
  }
  arrayLength = sizeof(IR_OFF) / sizeof(IR_OFF[0]);
  for (i = 0; i < arrayLength; i++) {
    if (IR_OFF[i] == dataToFind)return TURN_LIGHT_OFF;
  }
  arrayLength = sizeof(IR_SHINE) / sizeof(IR_SHINE[0]);
  for (i = 0; i < arrayLength; i++) {
    if (IR_SHINE[i] == dataToFind)return INCREASE_LIGHT;
  }
  arrayLength = sizeof(IR_TIMER) / sizeof(IR_TIMER[0]);
  for (i = 0; i < arrayLength; i++) {
    if (IR_TIMER[i] == dataToFind)return TIMER_ON;
  }
  //  arrayLength = sizeof(IR_TRY) / sizeof(IR_TRY[0]);
  //  for (i = 0; i < arrayLength; i++) {
  //if (IR_TIMER[i] == dataToFind)return TURN_LIGHT_ON;
  //  }
}
