# arduinoLightControler
The lightcontroler for the mame button lights

# WHAT YOU NEED
- A arduino (I used a Nano)
- Launchbox (tested) or Hyperspin (not tested)
- The lights attached to the arduino (pin 4/9)

# HOW IT WORKS
The repo is split up in 2 parts, the arduino code and LEDBlinky.exe.
Upload the buttons_animations.ino code to you're arduino with the IDE,
And connect it to your PC (default COM2)

Open Launchbox and go to the LEDBlinky options in the settings menu.
Select the LEDBlinky project file and save the settings, no extra files needed.
Launchbox wil now send the trigger commands to the .EXE file with wil pass serial signals to the arduino.
The arduino will then play the animation that is predefined.

# THE PINS
led0 = 4;
led1 = 5;
led2 = 6;
led3 = 7;
led4 = 8;
led5 = 9;
