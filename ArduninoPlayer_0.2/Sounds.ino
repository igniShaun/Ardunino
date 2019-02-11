void buzzOn( byte which ){
  switch( which ){
    case 1:
    buzzLow();
    break;
    case 2:
    buzzMid();
    break;
    case 3:
    buzzHigh();
    break;
    default:
    break;
  }
}
void buzzOff() { analogWrite( Buzzer, 0 );   }
void buzzLow() { analogWrite( Buzzer, 4 );   }
void buzzMid() { analogWrite( Buzzer, 125 ); }
void buzzHigh(){ analogWrite( Buzzer, 255 ); }
