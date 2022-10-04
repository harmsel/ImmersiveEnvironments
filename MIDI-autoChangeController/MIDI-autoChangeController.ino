#include "MIDIUSB.h"
#include "Ultrasonic.h"
Ultrasonic ultrasonic(13);  //Pin 13

int pos = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  for (pos = 0; pos <= 120; pos += 1) {  // goes from 0 degrees to 180 degrees
    controlChange(0, 10, pos);
    MidiUSB.flush();
    Serial.println("pos: ");
    Serial.print(pos);  // waits 15 ms for the servo to reach the position
    delay(10);
  }
  for (pos = 120; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
    controlChange(0, 10, pos);
    MidiUSB.flush();
    Serial.println("pos: ");
    Serial.print(pos);  
     delay (10);
  }




  delay(1000);  //onthaasten
}


// -- hieronder de functies nodig voor MIDI
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