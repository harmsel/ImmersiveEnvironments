## Quickstart Arduino Mac (& Windows)  
### install Arduino Software 
Download and install Arduino IDE (not the online IDE/web editor) https://www.arduino.cc/en/Main/Software 
MAC: Move the file  ‘Arduino’ to ‘Apps’  
Start Arduino from Applications  

### Set UI to Englisch 
To be more inline with documentation here and online 
Go to 'Arduino' → ' Preferences  
Pick “Editor language:” use ‘english’ 
Connect board (USB cable) and select board: Arduino MICRO from the dropdown. You should see the port: /dev/cu.usbmodem*** or simular (Windows = Com port) 
(if your board )

### Upload your code
File → examples→ Basic → Blink 
Compile and upload: you can use  ‘Command - U'  
If you see 'Done uploading' it worked!  

### Blink code adjustment 
The blue led on the board is blinking (1 second/1 second) 
Change the frequency of the blinking led in the code, upload again. Can you see the difference?  

 
## Install/remove a Library  

Open Arduino 
Go to Tools > Manage Libraries 
Search for “Grove Ultrasonic ranger” 
Install and close Library management’ 
Go to File > Examples and check if the “Grove Ultrasonic Ranger” is installed. 

Remove: Go to 'Arduino' → ' Preferences . You will find the 'Sketchbook location' Open en find the location of the Libraries
Remove using finder. (normaly are the libs in Documents/Arduino/Libraries)

## Fixing errors
There are two kinds of errors:
- Errors connecting with USB (happens to much)
- Errors in code

Upload an empy sketch (press command+n) and (command+u). If uploading fails it is port/USB/connection problem.

#### Connection (USB/port) problems
- Select the board and select the port
    -  Not possible? Use another (physical) USB port on your laptop
    - Use another cable
    - Use another Arduino
- The Arduino and port are available
    - Use the blink code
    
# Interactive Madmapper & Ableton (see below) 

### Node/Arduino chart (you need this later) 
https://diymidicontroller.com/midi-note-chart/ 

 
### Install the MIDI library  

Arduino: Tools > manage Libraries...  >‘MIDIUSB’ 

 

### Upload MIDI Sketch 

* Find: examples > MIDIUSB > MIDIUSB_WRITE (scroll down) 
* Upload this (If you don’t see “Done Uploading” you have to fix this!) 
* Open Serial Monitor, click on search icon right top of your screen 
* See how the Micro is sending MIDI Notes to your Laptop  

## View the MIDI communication 
* Download MID+I View or find in appstore: Midiview 
* Open MidiView 
* Click Enable 
* Select Arduino MIcro 
You should be able to see the notes  de MidiView

## Generate MIDI using the distance sensor 
* Copy the code from: https://github.com/harmsel/ImmersiveEnvironments/ 
* Check if data is received by MidiView  

## Control Madmapper with distance sensor (Arduino) 
* Make two scenes (Dropdown: Scenes/ Cues 
* Attach a MIDI controll to start each scene (dropdown: controll list) > Learn MIDI 
* Go to Scenes/ Cues > select a scene 
* Tigger a MIDI note ON (arduino) 
* Edit MIDI (in Control list) 

Video of steps above: 
https://vimeo.com/753106105

💡🚀TIP: If you want to test what switching between scenes looks like. Then use your keyboard to fake the interaction for testing. Then instead of MIDI, choose Keyboard 

# Make Ableton interactive - Using external sensors 
How it works: Sensor -> MICRO-> Seeeduino -> MIDI -> Ableton 

### Ableton MIDI settings 
* Live > Preferences > Link/tempo/MIDI > MIDI ports.  
* select Micro: Track and Remote
* Check if MIDI Is received by Ableton 

In the top, on the far right, two squares next to each other. You see the yellow block light up very briefly at MIDI input. (see screenshot below) 

Video (DUTCH only! So if you don’t get it, let me know ASAP): https://www.youtube.com/watch?v=XS0JlHeDmTY 

All Code examples: 

https://github.com/harmsel/ImmersiveEnvironments 

 

 

 

 
