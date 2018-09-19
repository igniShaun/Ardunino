/* Arduniño! The Arduino for niñas, niños and anyone new to electronics
   0.1 -- Basic Arduino tutorials all crammed together, with different pinouts
*/

// Pin definition
#define BlinkOut 2

#define MomentaryIn A6
#define MomentaryOut 3

#define ToggleIn A5
#define ToggleOut 4

#define ResistanceIn1 A4
#define ResistanceIn2 A3
#define ResistanceOut1 5
#define ResistanceOut2 6

#define SimonIn1 A2
#define SimonIn2 A1
#define SimonOut1 7
#define SimonOut2 8

/* Tutorial exercise specific variables */
// Blink
unsigned long BlinkTime = 0;
int BlinkSwitch = 1000; // How many ms to wait between switches
int BlinkStatus = LOW;

// Toggle
byte toggleState = 0;
byte toggleRead = 0;
byte lastToggleRead = 0;
int toggleFlip = LOW;
unsigned long lastToggleBounce = 0;

// Resistance trigger -- When a change in resistance is noticed in the pins, it will turn the corresponding LED on. 
/*unsigned long resPulseTimer = 0;
int resPulseRange = 1021;*/
int resistance1State = 0;
int resistance1Read = 0;
int lastResistance1Read = 0;
unsigned long Resistance1Hold = 0;
int resistance2State = 0;
int resistance2Read = 0;
int lastResistance2Read = 0;
unsigned long Resistance2Hold = 0;
int resistanceBounceThreshold = 100; // How much fluctuation in the analog read to tolerate before triggering

// Two-button Simon
bool simonRead = false; // False when playing a sequence, True when reading input
byte simonIn1State = 0;
byte simonIn1Read = 0;
byte lastSimonIn1Read = 0;
unsigned long lastSimon1Bounce = 0;
byte simonIn2State = 0;
byte simonIn2Read = 0;
byte lastSimonIn2Read = 0;
unsigned long lastSimon2Bounce = 0;
String sequence;
int simonToken = 0;
int simonPaws = 500;
int newGameDelay = 1000;

// Utility variables
unsigned long now;
int debounceDelay = 50;
int paws = 250;

void setup() {
  Serial.begin(9600);
  pinMode( BlinkOut, OUTPUT );

  pinMode( MomentaryIn, INPUT );
  pinMode( MomentaryOut, OUTPUT );
  digitalWrite( MomentaryOut, LOW );

  pinMode( ToggleIn, INPUT );
  pinMode( ToggleOut, OUTPUT );
  digitalWrite( ToggleOut, LOW );

  pinMode( ResistanceIn1, INPUT );
  pinMode( ResistanceOut1, OUTPUT );
  pinMode( ResistanceIn2, INPUT );
  pinMode( ResistanceOut2, OUTPUT );
  digitalWrite( ResistanceOut1, LOW );
  digitalWrite( ResistanceOut2, LOW );

  pinMode( SimonIn1, INPUT );
  pinMode( SimonIn2, INPUT );
  pinMode( SimonOut1, OUTPUT );
  pinMode( SimonOut2, OUTPUT );
  newSimon();
}

void loop() {
  // Blink
  Blink();

  // Momentary
  Momentary();

  // Toggle
  Toggle();

  // Resistance-to-pulsor
  Resistor();

  // Simon
  Simon();

  // Don't break stuff
  delay(10);
}
