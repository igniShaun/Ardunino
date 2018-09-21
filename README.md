# Arduniño
Arduniño is an Arduino kit for children 6+ that is play first, STEAM education second, with a target price of $6 when purchasing for quantities of 50+.

Objectives:
1) Be fun for children.
2) Be affordable enough to be given away by wonderful people.

Key Results:
1) Most children make it through introductory Level 1 exercises without loss of interest or lack of understanding.
2) Some children experiment with their own configurations.
3) Most children, when offered, want to keep the kit.

Technical constraints:
- Standalone functionality -- We can't assume the children will have access to a computer at home.
- No on-site soldering / assembling / tools should be needed -- We assume these will not be available.

Levels:
1) Preprogrammed functions / games
2) Scratch for Arduino programming at library
3) Arduino IDE tutorials at library

Hardware:
- 1 x Arduino Nano clone
- 1 x mini breadboard
- 1 x PCB (optional)
- 3 x LEDs
- 2 x buttons
- 1 x buzzer
- 10 x breadboard wires
- 5 x breadboard-to-alligator-clip wires

Arduniño tutorial:
Level 1:
Plug the nano into the breadboard. Use a wire to connect the 5V pin to the red voltage rail, and use another color wire to connect the GND pin to connect to the blue voltage rail. You're ready to go!
- Blink: Plug an LED with the long leg in pin D2, and connect the short leg to the blue voltage rail. You've made it blink!
- Momentary: What if you want to control when the light turns on? Plug an LED with the long leg in pin D3, and connect the short leg to the blue voltage rail. Make a button connect A7 and the red voltage rail. Now when you want the light on, just hold the button!
- Toggle: What if you don't want to hold the button? Plug an LED with the long leg in pin D4, and connect the short leg to the blue voltage rail. Make a button connect A6 and the red voltage rail. Now when you want the light on, press the button! If you want it off, press the button again!
- Resistance sensor: Did you know? Electricity flows easily through metal, but it can also go through other things (just not as well!). Connect LEDs to pins D5 and D6, then connect wires to A3 and A4. When you touch them to things that have a different electrical resistance, the LEDs will turn on. Try them on different things, like a banana!
- Simon: Let's play a game! Connect LEDs to pins D7 and D8, and connect buttons to A1 and A2. Hold both buttons for a second to start a new game--the lights will blink and chase, then one of the LEDs will light up. Press the button that matches that LED. That LED will light up again, then one of the two will light up. Repeat the sequence back! It will keep adding one more to the sequence every time you repeat it correctly. How many can you remember?

To add:
- Gopher chase -- Hook multiple kits together, a lit LED will chase around the kits. Pressing the corresponding button when lit catches it, otherwise, gopher speeds up or reverses.
- PCB design (optional):
- Small piano keys -- To play with music and electrical resistance (Credit to https://mitxela.com/projects/stylocard)
- Trace maze -- To play with dexterity practice and electrical conductivity
