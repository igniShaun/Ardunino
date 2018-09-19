void Momentary(){
  if ( analogRead( MomentaryIn ) > 1020 )
    digitalWrite( MomentaryOut, HIGH );
  else
    digitalWrite( MomentaryOut, LOW );
}
