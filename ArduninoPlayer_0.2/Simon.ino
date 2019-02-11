// Three-button Simon
String sequence;
int simonToken = 0;
const int defaultSimonPaws = 400;
int simonPaws = defaultSimonPaws;

// New Simon game sequence
void newSimon() {
  // simonRead = false;
  buzzLow();
  digitalWrite( LED1, HIGH );
  delay(paws);
  buzzMid();
  digitalWrite( LED2, HIGH );
  delay(paws);
  buzzHigh();
  digitalWrite( LED3, HIGH );
  delay(paws*2);
  buzzOff();
  digitalWrite( LED1, LOW );
  digitalWrite( LED2, LOW );
  digitalWrite( LED3, LOW );
  delay(paws);
  buzzMid();
  digitalWrite( LED1, HIGH );
  digitalWrite( LED2, HIGH );
  digitalWrite( LED3, HIGH );
  delay(paws);
  buzzOff();
  digitalWrite( LED1, LOW );
  digitalWrite( LED2, LOW );
  digitalWrite( LED3, LOW );
  sequence = "";
  simonToken = 0;
  simonPaws = defaultSimonPaws;
  simonPlay();
}

// Handles input
void simonPressed( byte button ) {
  if ( button == 1 && sequence[simonToken] == '1' ) { // Correct 1
    buzzLow();
    lightOn(button);
    simonToken++;
  }
  else if ( button == 2 && sequence[simonToken] == '2' ){ // Correct 2
    buzzMid();
    lightOn(button);
    simonToken++;
  }
  else if ( button == 3 && sequence[simonToken] == '3' ){ // Correct 2
    buzzHigh();
    lightOn(button);
    simonToken++;
  }
  else{ // Incorrect. Lose sequence and reset game.
    showFull();
    buzzMid();
    digitalWrite( LED1, HIGH );
    digitalWrite( LED2, HIGH );
    digitalWrite( LED3, HIGH );
    delay( paws * 3 );
    buzzLow();
    digitalWrite( LED1, LOW );
    digitalWrite( LED2, LOW );
    digitalWrite( LED3, LOW );
    delay( paws * 2);
    buzzOff();
    showNone();
    newSimon();
  }
}
void simonReleased( byte button ){
  buzzOff();
  lightOff(button);
  
  if( simonToken == sequence.length() )
    simonPlay();
}

// Simon's turn to play / add to the sequence
void simonPlay() {
  // simonRead = false;
  delay(simonPaws);
  if( sequence.length() % 2 == 1 ) // Speed up every 2
    simonPaws *= 0.9;
  for ( int i = 0; i < sequence.length(); i++ ) {
    if ( sequence[i] == '1' ) {
      buzzLow();
      lightOn(1);
      delay(simonPaws);
      buzzOff();
      lightOff(1);
      delay(simonPaws);
    }
    else if( sequence[i] == '2' ) {
      buzzMid();
      lightOn(2);
      delay(simonPaws);
      buzzOff();
      lightOff(2);
      delay(simonPaws);
    }
    else{
      buzzHigh();
      lightOn(3);
      delay(simonPaws);
      buzzOff();
      lightOff(3);
      delay(simonPaws);
    }
  }
  randomSeed( millis() );
  byte rando = random( 0, 255 ) % 3 + 1;
  if ( rando == 1 ) {
    sequence += '1';
    lightOn(1);
    buzzLow();
    delay( simonPaws );
    buzzOff();
  }
  else if( rando == 2 ) {
    sequence += '2';
    lightOn(2);
    buzzMid();
    delay( simonPaws );
    buzzOff();
  }
  else{
    sequence += '3';
    lightOn(3);
    buzzHigh();
    delay( simonPaws );
    buzzOff();
  }
  lightsOff();
  simonToken = 0;
  showScore( sequence.length() );
  // In case they're holding buttons during this
  unpress();
}
