// Blink vars
unsigned long LastBlink = 0;
const int BlinkInt = 1000; // How many ms to wait between switches
int BlinkStatus = LOW;

void Blink() {
  if ( now - LastBlink > BlinkInt ) {
    BlinkStatus = !BlinkStatus;
    digitalWrite( BlinkLED, BlinkStatus );
    LastBlink = now;
  }
}

