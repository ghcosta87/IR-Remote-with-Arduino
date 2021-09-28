void checkTimer() {
  long timeNow = millis();
  if (timerActive) {
    writeOutput(TURN_LIGHT_ON);
    if ((timeNow - zeroTime) > PRESET_TIMER)  {
      if (SERIAL_DEBUG)Serial.println("Fim do tempo");
      writeOutput(TURN_LIGHT_OFF);
      timerActive=false;
    } else {
      if (SERIAL_DEBUG)Serial.print("ainda tem: ");
      if (SERIAL_DEBUG)Serial.print(((timeNow - zeroTime) - PRESET_TIMER) / 60000);
      if (SERIAL_DEBUG)Serial.println(" minutos");
      if (SERIAL_DEBUG)Serial.println(PRESET_TIMER);
      if (SERIAL_DEBUG)Serial.println((timeNow - zeroTime));
    }
  }
}
