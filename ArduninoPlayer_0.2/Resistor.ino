// Voltage / resistance pulsor -- Flash the corresponding LED based on the A2D input
const int resWindow = 1020;
unsigned long resTimer = 0;
// int resRead = 0;

void Resistor(){
  // Live read
  if( now - resTimer > resWindow ){
    resTimer = now;
  }

  if( now - resTimer >= analogRead( ResistanceIN ) ){
    digitalWrite( ResLED, HIGH );
    buzzHigh();
  }
  else{
    digitalWrite( ResLED, LOW );
    buzzOff();
  }
}
