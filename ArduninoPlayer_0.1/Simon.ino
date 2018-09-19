void Simon(){
  if ( analogRead( SimonIn1 ) > 1020 ) simonIn1Read = 1;
  else simonIn1Read = 0;
  if ( simonIn1Read != lastSimonIn1Read ) lastSimon1Bounce = millis();
  lastSimonIn1Read = simonIn1Read;
  if ( millis() - lastSimon1Bounce > debounceDelay ) {
    if ( simonIn1Read != simonIn1State ) {
      simonIn1State = simonIn1Read;
      if ( simonIn1State == 1 ) {
        simonInput( 1 );
      }
    }
  }
  if ( analogRead( SimonIn2 ) > 1020 ) simonIn2Read = 1;
  else simonIn2Read = 0;
  if ( simonIn2Read != lastSimonIn2Read ) lastSimon2Bounce = millis();
  lastSimonIn2Read = simonIn2Read;
  if ( millis() - lastSimon2Bounce > debounceDelay ) {
    if ( simonIn2Read != simonIn2State ) {
      simonIn2State = simonIn2Read;
      if ( simonIn2State == 1 ) {
        simonInput( 2 );
      }
    }
  }
}

// New Simon game sequence
void newSimon() {
  simonRead = false;
  digitalWrite( SimonOut1, HIGH );
  delay(paws);
  digitalWrite( SimonOut2, HIGH );
  delay(paws);
  digitalWrite( SimonOut1, LOW );
  delay(paws);
  digitalWrite( SimonOut2, LOW );
  delay(paws);
  digitalWrite( SimonOut2, HIGH );
  delay(paws);
  digitalWrite( SimonOut1, HIGH );
  delay(paws);
  digitalWrite( SimonOut2, LOW );
  delay(paws);
  digitalWrite( SimonOut1, LOW );
  delay(paws);
  digitalWrite( SimonOut1, HIGH );
  digitalWrite( SimonOut2, HIGH );
  delay(paws);
  digitalWrite( SimonOut1, LOW );
  digitalWrite( SimonOut2, LOW );
  delay(simonPaws);
  sequence = "";
  simonToken = 0;
  // In case they're holding the buttons during the splash, the input won't be recorded
  simonIn1State = 1;
  simonIn2State = 1;
}

// Handles input
void simonInput( int button ) {
  if ( button == 1 && sequence[simonToken] == '1' ) { // Correct 1
    digitalWrite( SimonOut1, HIGH );
    delay(paws);
    digitalWrite( SimonOut1, LOW );
    simonToken++;
  }
  else if ( button == 2 && sequence[simonToken] == '2' ){ // Correct 2
    digitalWrite( SimonOut2, HIGH );
    delay(paws);
    digitalWrite( SimonOut2, LOW );
    simonToken++;
  }
  else{ // Incorrect. Lose sequence and reset game.
    digitalWrite( SimonOut1, HIGH );
    digitalWrite( SimonOut2, HIGH );
    delay(simonPaws * 2);
    digitalWrite( SimonOut1, LOW );
    digitalWrite( SimonOut2, LOW );
    delay(simonPaws * 2);
    newSimon();
  }
  if( simonToken == sequence.length() )
    simonPlay();
}
// Simon's turn to play / add to the sequence
void simonPlay() {
  simonRead = false;
  for ( int i = 0; i < sequence.length(); i++ ) {
    if ( sequence[i] == '1' ) {
      digitalWrite( SimonOut1, HIGH );
      delay(simonPaws);
      digitalWrite( SimonOut1, LOW );
      delay(simonPaws);
    }
    else {
      digitalWrite( SimonOut2, HIGH );
      delay(simonPaws);
      digitalWrite( SimonOut2, LOW );
      delay(simonPaws);
    }
  }
  randomSeed( millis() );
  if ( random(1, 2) == 1 ) {
    sequence += '1';
    digitalWrite( SimonOut1, HIGH );
    delay(simonPaws);
    digitalWrite( SimonOut1, LOW );
  }
  else {
    sequence += '2';
    digitalWrite( SimonOut2, HIGH );
    delay(simonPaws);
    digitalWrite( SimonOut2, LOW );
  }
  simonToken = 0;
  simonRead = true;
}
