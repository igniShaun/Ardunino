// Toggle vars
int toggleFlip = LOW;
byte toggleState = 0, toggleRead = 0, pToggleRead = 0;
unsigned long ToggleBounce = 0;

void Toggle(){
  if ( digitalRead( ButtonTog ) == 0 ) toggleRead = 1;
  else toggleRead = 0;
  if ( toggleRead != pToggleRead ) ToggleBounce = now;
  pToggleRead = toggleRead;
  if ( now - ToggleBounce > debounceDelay ) {
    if ( toggleState != toggleRead ) {
      toggleState = toggleRead;
      if ( toggleState == 1 ) {
        toggleFlip = !toggleFlip;
        digitalWrite( ToggleLED, toggleFlip );
      }
    }
  }
}
