byte leftScore = 0;
byte rightScore = 0;

void momentaryDown( byte whichOne ){
  switch( whichOne ){
    case 1:
    digitalWrite( LED1, HIGH );
    buzzLow();
    rScore();
    break;

    case 2:
    digitalWrite( LED2, HIGH );
    buzzMid();
    lScore();
    break;

    case 3:
    digitalWrite( LED3, HIGH );
    buzzHigh();
    resetScore();
    break;

    default:
    break;
  }
}

void momentaryUp( byte whichOne ){
  buzzOff();
  switch( whichOne ){
    case 1:
    digitalWrite( LED1, LOW );
    break;

    case 2:
    digitalWrite( LED2, LOW );
    break;

    case 3:
    digitalWrite( LED3, LOW );
    break;

    default:
    break;
  }
}
void rScore(){
  rightScore++;
  if( rightScore >= 100 ) rightScore = 0;
  showScore( leftScore, rightScore );
}

void lScore(){
  leftScore++;
  if( leftScore >= 100 ) leftScore = 0;
  showScore( leftScore, rightScore );
}

void resetScore(){
  leftScore = 0;
  rightScore = 0;
  showScore( leftScore, rightScore );
}
