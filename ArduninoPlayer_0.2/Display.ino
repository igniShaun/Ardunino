// LEDs
void lightOn( byte which ){
  switch( which ){
    case 1:
    digitalWrite( LED1, HIGH );
    break;
    case 2:
    digitalWrite( LED2, HIGH );
    break;
    case 3:
    digitalWrite( LED3, HIGH );
    break;
    default:
    break;
  }
}
void lightOff( byte which ){
  switch( which ){
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
void lightsOff(){
  digitalWrite( LED1, LOW );
  digitalWrite( LED2, LOW );
  digitalWrite( LED3, LOW );
}
// TM1637
uint8_t FULL[] = { 0xff, 0xff, 0xff, 0xff };
uint8_t BLANK[] = { 0x00, 0x00, 0x00, 0x00 };

const uint8_t HI[] = {
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G, // H
  SEG_B | SEG_C, // I
  0x00,0x00
};
const uint8_t HOLA[] = {
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G, // H
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
  SEG_D | SEG_E | SEG_F, // L
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G // A
};
const uint8_t OI[] = {
  0x00,
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
  SEG_E, // I
  0x00
};

const uint8_t BUBBLES1[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,
  SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_B | SEG_F | SEG_G,
  SEG_C | SEG_D | SEG_E | SEG_G
};
const uint8_t BUBBLES2[] = {
  SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_B | SEG_F | SEG_G,
  SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_B | SEG_F | SEG_G
};

void showScore( byte left, byte right ){
  display.showNumberDecEx(left * 100 + right, (0x80>>1),true);
}

void showScore( int showMe ){
  display.showNumberDec( showMe, false );
}

void showBubbles(){
  display.setSegments( BUBBLES1 );
  delay( paws );
  display.setSegments( BUBBLES2 );
  delay( paws );
  display.setSegments( BUBBLES1 );
  delay( paws );
  display.setSegments( BUBBLES2 );
  delay( paws );
}

void showHi() { display.setSegments(HI); }
void showHola() { display.setSegments(HOLA); }
void showOi() { display.setSegments(OI); }
void showFull(){ display.setSegments(FULL); }
void showNone(){ display.setSegments(BLANK); }
