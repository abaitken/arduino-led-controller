# Arduino Addressable LED Controller

Various animations, patterns and timings for addressable LED lights.

## Before Building

The sketch contains secrets used when connecting to a wifi network. 

To successfully build the sketch copy the secrets-example.h file and rename it as secrets.h. 

Edit the file and replace the secrets as required. secrets.h must be ignored from the commit.

## Sequence start

When the sequence begins the lights with switch off.

Followed by indexed leds indicating states:

- 0: Lighting initialisation
  - Green: OK
- 1: Network initialisation
  - Red: Start/No shield detected
  - Orange: Connecting
  - Green: Connected

After this the lights will be reset off and the sequences will begin.


## TODO

- Implement animations:
    - Combination animations
        - One followed by another
    - Nightrider
		- Combo sections slide left + slide irght
    - Section Loop around
		- Combo sections slide left/right multiple times
    - Twinkling
- Implement timings
    - Repeating set of values (e.g. 25ms then 10ms then 50ms, repeat)
    - Add microphone and support bpm?
- Implement patterns
    - Colour stops with various different calculations for inbetween colours
    - Colour sections
	- Store random colour values to support consistent colours when shifting
- Define sequences via parsing a special string
	- e.g. 'A=FR;P=R;T=C,25;A=FL' (Animation fill right, Palette is random, Timing is constant 25ms, then animate Fill left, then repeat)
	- Subsequent palettes/timings just change the current settings until overridden
	- Provide brightness override
- Implement LAN communication
	- Implement wifi module
	- Implement a technique to send instructions
		- Post a string to a simple web server with various patterns/palettes etc?
		- Create RPI app to provide controls for sending string

## Bugs

- Sometimes there is a long pause on a single pattern
- Sometimes there an odd color left over on the first/last LED
- Fade out animation does not seem to be working
- Some of the new animations are not working or causing the arduino to crash and reboot
- Network connection is getting stuck