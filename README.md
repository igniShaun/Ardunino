# Arduniño
Arduniño is an Arduino kit for children 8+ that is play first, STEAM education second, with a target price of $6 when purchasing for quantities of 50+.

Objectives:
1) Be fun for children.
2) Be affordable enough to be given away by wonderful people.

Key Results:
1) Most children make it through introductory exercises without loss of interest or lack of understanding.
2) Some children experiment with their own configurations.
3) Most children, when offered, want to keep the kit.

Technical constraints:
- Standalone functionality -- We can't assume the children will have access to a computer at home.
- No on-site soldering / assembling / tools should be needed -- We assume these will not be available.

Levels:
1) Preprogrammed functions / games
2) Scratch for Arduino programming at library

Hardware:
- 1 x Arduino Nano clone
- 1 x mini breadboard
- 1 x PCB (optional)
- 3 x LEDs
- 2 x buttons
- 1 x buzzer
- 10 x breadboard wires
- 5 x breadboard-to-alligator-clip wires

Software functionality:
- Resistance sensor -- detects resistance between pins, and sends output to corresponding pin. Similar function to the excellent Makey Makey.
- Zero -- Detects state of pins and records them for reference -- onboard reset(?)
- Blink -- One output pin just blinks an LED or buzzer
- Momentary -- Light turns on when button is pressed, turns off when released
- Toggle -- Pressing button toggles light.
- Simon -- Game where player mimics the blinked pattern.
- Gopher chase -- Hook multiple kits together, a lit LED will chase around the kits. Pressing the corresponding button when lit catches it, otherwise, gopher speeds up or reverses.

PCB design (optional):
- Small piano keys -- To play with music and electrical resistance
- Trace maze -- For dexterity practice and teaching electrical conductivity
