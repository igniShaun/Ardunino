// Button vars
const byte debounceDelay = 50;
byte button1State = 0, button1Read = 0, pButton1Read = 0, button1Low = 25; // 'Low' threshold is to address the marginal pull-up resistor performance in less expensive clones
unsigned long button1Bounce = 0;
byte button2State = 0, button2Read = 0, pButton2Read = 0, button2Low = 25;
unsigned long button2Bounce = 0;
byte button3State = 0, button3Read = 0, pButton3Read = 0, button3Low = 25;
unsigned long button3Bounce = 0;

void Buttons(){
  // Button 1
  if( analogRead(Button1) < button1Low ) button1Read = 1;
  else button1Read = 0;
  if( button1Read != pButton1Read ) button1Bounce = now;
  pButton1Read = button1Read;
  if( now - button1Bounce > debounceDelay ){
    if( button1Read != button1State ){
      button1State = button1Read;
      FSM( 1, button1State );
    }
  }

  // Button 2
  if( analogRead(Button2) < button2Low ) button2Read = 1;
  else button2Read = 0;
  if( button2Read != pButton2Read ) button2Bounce = now;
  pButton2Read = button2Read;
  if( now - button2Bounce > debounceDelay ){
    if( button2Read != button2State ){
      button2State = button2Read;
      FSM( 2, button2State );
    }
  }

  // Button 3
  if( analogRead(Button3) < button3Low ) button3Read = 1;
  else button3Read = 0;
  if( button3Read != pButton3Read ) button3Bounce = now;
  pButton3Read = button3Read;
  if( now - button3Bounce > debounceDelay ){
    if( button3Read != button3State ){
      button3State = button3Read;
      FSM( 3, button3State );
    }
  }
}

void FSM( byte button, byte pressed ){ // Change button behavior based on state
  switch( mode ){
    case 0: // Momentary / counter
    if( pressed == 1 )
      momentaryDown( button );
    else
      momentaryUp( button );
    break;

    case 1: // RPS
    if( pressed == 1 )
      RPSpressed( button );
    //else
      //RPSReleased( button );
    break;

    case 2: // Simon
    if( pressed == 1 )
      simonPressed( button );
    else
      simonReleased( button );
    break;
  }
}

void unpress(){
  button1State = 0;
  button1Read = 0;
  pButton1Read = 0;

  button2State = 0;
  button2Read = 0;
  pButton2Read = 0;

  button3State = 0;
  button3Read = 0;
  pButton3Read = 0;
}
