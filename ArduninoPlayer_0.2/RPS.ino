// RPS
void resetRPS(){
  buzzHigh();
  digitalWrite( LED3, HIGH );
  delay(paws);
  digitalWrite( LED3, LOW );
  buzzMid();
  digitalWrite( LED2, HIGH );
  delay(paws);
  digitalWrite( LED2, LOW );
  buzzLow();
  digitalWrite( LED1, HIGH );
  delay(paws);
  digitalWrite( LED1, LOW );
  buzzMid();
  digitalWrite( LED2, HIGH );
  delay(paws);
  digitalWrite( LED2, LOW );
  buzzOff();
  resetScore();
}

void newRPS(){
  // simonRead = false;
  unpress();
}

void RPSpressed( byte button ){ // 1 = rock < 2 = paper < 3 = scissor
  // MCU's choice
  randomSeed( millis() );
  byte rando = random( 0, 255 ) % 3 + 1;
  
  // Reveal choices
  lightOn( rando ); 
  lightOn( button );
  buzzOn( button );
  delay( paws*2 );
  buzzOff();
  delay(paws);
  
  // 1 = rock < 2 = paper < 3 = scissor
  if( rando == button ){ // Tie
    for( int i = 0; i < 2; i++ ){
      lightOn( button );
      buzzMid();
      delay(paws);

      lightOff( button );
      buzzOff();
      delay(paws);
    }
  }
  else if( button-1 == rando || button==3 && rando==1 ){ // Lose
    lightOff( rando );
    for( int i = 0; i < 3; i++ ){
      lightOn( button );
      buzzMid();
      delay(paws);
    
      lightOff( button );
      buzzHigh();
      delay(paws);
    }
    buzzOff();
    rScore();
  }
  else{ // Win
    lightOff( button );
    lightOn( rando );
    buzzMid();
    delay(paws*2);
    
    buzzLow();
    delay(paws*2);
    
    lightOff( rando );
    buzzOff();
    lScore();
  }
  delay(paws*2);
  newRPS();
}
