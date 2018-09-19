void Toggle(){
  if ( analogRead( ToggleIn ) > 1020 ) toggleRead = 1;
  else toggleRead = 0;
  if ( toggleRead != lastToggleRead ) lastToggleBounce = millis();
  lastToggleRead = toggleRead;
  if ( millis() - lastToggleBounce > debounceDelay ) {
    if ( toggleState != toggleRead ) {
      toggleState = toggleRead;
      if ( toggleState == 1 ) {
        toggleFlip = !toggleFlip;
        digitalWrite( ToggleOut, toggleFlip );
      }
    }
  }
}
