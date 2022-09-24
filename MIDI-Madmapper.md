
# Interactive Madmapper & Ableton (see below) 

### Node/Arduino chart (you need this later) 
[https://diymidicontroller.com/midi-note-chart/ ]()
 


### Upload MIDI Sketch 

1. In the menu bar Arduino IDE  (scroll down): File > Examples > MIDIUSB > MIDIUSB_WRITE
2. Upload 
3. Open Serial Monitor, click on search icon right top of your screen 

### View the MIDI communication 
1. Download MIDI View: https://hautetechnique.com/midi/midiview/
2. Open MidiView 
3. Click Enable 
4. Select Arduino Micro (You should be able to see the notes  de MidiView)

![](images/midiView.png)

### Generate MIDI using the distance sensor 
1. Copy/download/fork the code from:[MIDI-distance_NoteOn](https://github.com/harmsel/ImmersiveEnvironments/tree/main/MIDI-distance_NoteOn)
2. Follow instructions in this code how to connect your Distance sensor
3. Upload the code en check the data in the Serial Monitor (Arduino)  
4. Check if data is received by MidiView  

## Control Madmapper with distance sensor (Arduino) 
1. Make two scenes (Dropdown: Scenes/ Cues 
2. Attach a MIDI controll to start each scene (dropdown: controll list) > Learn MIDI 
3. Go to Scenes/ Cues > select a scene 
4 Tigger a MIDI note ON (arduino) 
* Edit MIDI (in Control list) 

Attaching MIDI controls to Madmapper
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
