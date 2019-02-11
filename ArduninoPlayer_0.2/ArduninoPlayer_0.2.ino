#include <TM1637Display.h>

/* Arduniño! The Arduino for niñas, niños and anyone new to electronics
   0.1 -- Basic Arduino tutorials all crammed together, with different pinouts
   0.2 -- Change to constant inputs, contant output, and change jumper pin to switch all but basic arduino tutorial functions
          Display reference (if changed in future): https://playground.arduino.cc/Main/TM1637 and https://blog.3d-logic.com/2015/01/21/arduino-and-the-tm1637-4-digit-seven-segment-display/
   
*/

#define BlinkLED 2
#define LED1 3
#define LED2 4
#define LED3 5
#define ToggleLED 6
#define ResLED 7
#define DispCLK 8
#define DispDIO 9
#define Buzzer 11

#define Button1 A6
#define Button2 A5
#define Button3 A4
#define ButtonTog A3
#define ResistanceIN A2

#define RPSPin A1
#define SimonPin A0

// Display variables
TM1637Display display( DispCLK, DispDIO);

// Utility variables
unsigned long now;
const byte paws = 250;
const unsigned int superPaws = 1000;
byte mode = 0; // 0 = momentary/counter, 1 = Rock/Paper/Scissor, 2 = Simon
byte pMode = 20;

void setup() {
  Serial.begin(9600);
  
  pinMode( BlinkLED, OUTPUT );

  pinMode( Button1, INPUT_PULLUP );
  pinMode( LED1, OUTPUT );
  digitalWrite( LED1, LOW );
  pinMode( Button2, INPUT_PULLUP );
  pinMode( LED2, OUTPUT );
  digitalWrite( LED2, LOW );
  pinMode( Button3, INPUT_PULLUP );
  pinMode( LED3, OUTPUT );
  digitalWrite( LED3, LOW );

  pinMode( ButtonTog, INPUT_PULLUP );
  pinMode( ToggleLED, OUTPUT );
  digitalWrite( ToggleLED, LOW );

  pinMode( ResistanceIN, INPUT_PULLUP );
  pinMode( ResLED, OUTPUT );
  digitalWrite( ResLED, LOW );

  pinMode( RPSPin, INPUT_PULLUP );
  pinMode( SimonPin, INPUT_PULLUP );

  // Display init
  display.setBrightness(3);
  showHi();
  delay(superPaws);
  showHola();
  delay(superPaws);
  showOi();
  delay(superPaws);
  showBubbles();
  showNone();
}

void loop() {
  // First things first
  now = millis();
  
  // Blink
  Blink();

  // Toggle
  Toggle();

  // Resistance-to-pulsor
  Resistor();

  // Counter / RPS / Simon selector
  if( digitalRead( RPSPin ) == 0 ){ 
    mode = 1;
    if( mode != pMode ){
      resetRPS();
      newRPS();
    }
  }
  else if( digitalRead( SimonPin ) == 0 ){ 
    mode = 2;
    if( mode != pMode )
      newSimon();
  }
  else{
    mode = 0;
    if( mode != pMode )
      resetScore();
  }
  pMode = mode; // To track when mode is changed

  // Buttons capture
  Buttons();

  // Don't break stuff
  delay(3);
}
