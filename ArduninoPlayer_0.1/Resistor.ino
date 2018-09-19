void Resistor(){
  /* Instead of pulsing faster on lower resistance, get resistance of input, and turn on when resistance changes
  now = millis();
  if( now - resPulseTimer > resPulseRange ) resPulseTimer = now;
  if( analogRead( ResistanceIn ) <= now - resPulseTimer ) digitalWrite( ResistanceOut, LOW );
  else digitalWrite( ResistanceOut, HIGH );*/

  /*
#define ResistanceIn1 A4
#define ResistanceIn2 A3
#define ResistanceOut1 5
#define ResistanceOut2 6

int resistance1State = 0;
int resistance1Read = 0;
int lastResistance1Read = 0;
unsigned long Resistance1Hold = 0;
int resistance2State = 0;
int resistance2Read = 0;
int lastResistance2Read = 0;
unsigned long Resistance2Hold = 0;

int resistanceBounceThreshold 
*/

  resistance1Read = analogRead( ResistanceIn1 );
  if( abs( resistance1Read - lastResistance1Read ) > resistanceBounceThreshold ){ // Trigger resistor 1 output for a paws
    digitalWrite( ResistanceOut1, HIGH );
    Resistance1Hold = millis() + paws;
  }
  else if( millis() > Resistance1Hold ){ // If held stable long enough, turn off
    digitalWrite( ResistanceOut1, LOW );
  }
  lastResistance1Read = resistance1Read;

  resistance2Read = analogRead( ResistanceIn2 );
  if( abs( resistance2Read - lastResistance2Read ) > resistanceBounceThreshold ){ // Trigger resistor 2 output for a paws
    digitalWrite( ResistanceOut2, HIGH );
    Resistance2Hold = millis() + paws;
  }
  else if( millis() > Resistance2Hold ){ // If held stable long enough, turn off
    digitalWrite( ResistanceOut2, LOW );
  }
  lastResistance2Read = resistance2Read;
/*  Serial.print("Resistance 1: ");Serial.print(resistance1Read);
  Serial.print(" Resistance 2: ");Serial.println(resistance2Read);*/
}
