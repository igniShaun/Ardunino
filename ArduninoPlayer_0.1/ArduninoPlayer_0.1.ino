/* Arduniño! The Arduino for niñas, niños and anyone new to electronics
 * 0.1 -- Basic Arduino tutorials all crammed together, with different pinouts
 */

// Pin definition
#define BlinkPinOut 2
#define TogglePinOut 3
#define MomentaryPinIn A6
#define TogglePinIn A5
#define SimonIn1 A3
#define SimonIn2 A4
#define SimonOut1 5
#define SimonOut2 4

/* Tutorial specific variables */
// Blink
unsigned long BlinkTime = 0;
int BlinkSwitch = 1000;
int BlinkStatus = LOW;

// Toggle
bool toggleActive = false; // switches pinout between the momentary and toggle inputs
byte toggleState = 0;
byte toggleRead = 0;
byte lastToggleRead = 0;
unsigned long lastToggleBounce = 0;

// Two-button Simon
bool simonRead = false; // True when playing a sequence, False when recording input
byte simonIn1State = 0;
byte simonIn1Read = 0;
byte lastSimonIn1Read = 0;
unsigned long lastSimon1Bounce = 0;
byte simonIn2State = 0;
byte simonIn2Read = 0;
byte lastSimonIn2Read = 0;
unsigned long lastSimon2Bounce = 0;

// Utility variables
int debounceDelay = 50;

void setup() {
  pinMode( BlinkPinOut, OUTPUT );
  pinMode( TogglePinOut, OUTPUT );
  pinMode( SimonOut1, OUTPUT );
  pinMode( SimonOut2, OUTPUT );

  pinMode( MomentaryPinIn, INPUT );
  pinMode( TogglePinIn, INPUT );
  pinMode( SimonIn1, INPUT );
  pinMode( SimonIn2, INPUT );
}

void loop() {
  // Blink
  if( millis() > BlinkTime ){
    BlinkStatus = !BlinkStatus;
    digitalWrite( BlinkPinOut, BlinkStatus );
  }
  
  // Momentary / Toggle light
    // Momentary
  if( analogRead( MomentaryPinIn ) > 1020 ){
    digitalWrite( TogglePinOut, HIGH );
    toggleActive = false;
  }
  if( !toggleActive && analogRead( MomentaryPinIn ) < 1020 ) // Separate to avoid interfering with toggle
    digitalWrite( TogglePinOut, LOW );
    
    // Toggle
  if( analogRead( TogglePinIn ) > 1020 ) toggleRead = 1;
  else toggleRead = 0;
  if( toggleRead != lastToggleRead ) lastToggleBounce = millis();
  lastToggleRead = toggleRead;
  if( millis() - lastToggleBounce > debounceDelay ){
    if( toggleRead != toggleState ){
      toggleState = toggleRead;
      if( toggleState == 1 ) digitalWrite( TogglePinOut, HIGH );
      else digitalWrite( TogglePinOut, LOW );
      toggleActive = true;
    }
  }

  // Simon
  if( analogRead( SimonIn1 ) > 1020 ) simonIn1Read = 1;
  else simonIn1Read = 0;
  if( simonIn1Read != lastSimonIn1Read ) lastSimon1Bounce = millis();
  lastSimonIn1Read = simonIn1Read;
  if( millis() - lastSimon1Bounce > debounceDelay ){
    if( simonIn1Read != simonIn1State ){
      simonIn1State = simonIn1Read;
      // Action
    }
  }
  if( analogRead( SimonIn2 ) > 1020 ) simonIn2Read = 1;
  else simonIn2Read = 0;
  if( simonIn2Read != lastSimonIn2Read ) lastSimon2Bounce = millis();
  lastSimonIn2Read = simonIn2Read;
  if( millis() - lastSimon2Bounce > debounceDelay ){
    if( simonIn2Read != simonIn2State ){
      simonIn2State = simonIn2Read;
      // Action
    }
  }

/*
#define SimonIn1 A3
#define SimonIn2 A4
#define SimonOut1 5
#define SimonOut2 4
byte simonIn1State = 0;
byte simonIn1Read = 0;
byte lastSimonIn1Read = 0;
unsigned long lastSimon1Bounce = 0;
byte simonIn2State = 0;
byte simonIn2Read = 0;
byte lastSimonIn2Read = 0;
unsigned long lastSimon2Bounce = 0;*/
  
}
