#include "MIDIUSB.h"     //Library you have to install. Search for 'MIDIUSB' by Gary. Tools > Manage Libraries...  >‘MIDIUSB’
#include "Ultrasonic.h"  //install 'Grove Ultrasonic Ranger' by Seeed Studio. Arduino: Tools > Manage Libraries...

#include <elapsedMillis.h>  // Search for 'elapsedMillis' by Paul Stoffregen, via Arduino: Tools > Manage Libraries...
elapsedMillis timer;        // creates the object 'timer' you can make more by copy/paste this line (change to time1 time2 etc)

void setup() {
  Serial.begin(9600);  // enables the serial monitor, NEEDED. Open serial monitor = click right top of Arduino IDE
}

void loop() {
  if (timer == 1000) {  //if timer is 1000 miliseconds, do below (before closing '}')
    timer = 0;          //reset for the next loop

    noteOn(0, 48, 64);                                       // this is MIDI note E2 on");
    MidiUSB.flush();                                         // activate the Note command
    Serial.println("MIDI note E2 is 'pressed' and send to laptop via USB" );  // displays this text (String) in the serial monitor
  }

  delay(1);  //slows down the microcontroller to make Serial monitor output better readable
}


/// --- Below the functions to call in the loop --
// -----------------------------------------------
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = { 0x09, 0x90 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = { 0x08, 0x80 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
  MidiUSB.sendMIDI(event);
}