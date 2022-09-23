
#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);//plug in 7
int stopHammer=999;

void setup() {
  Serial.begin(115200);
}

void loop() {
  long distance;
  distance = ultrasonic.MeasureInCentimeters();
  Serial.print(distance); Serial.println(" cm");

  /// ---  if  distance is 2 cm, send note
  if (distance == 2 && stopHammer != 1 ) {
    Serial.println("note E2 aan");
    noteOn(0, 48, 64);
    MidiUSB.flush();
    stopHammer = 1;     
  }
  else if (distance < 5 && stopHammer != 2) {
    Serial.println("note D2 aan");
    noteOn(0, 50, 64);
    MidiUSB.flush();
       stopHammer = 2;  
  }
  else if (distance < 10 && stopHammer != 3) {
    Serial.println("note C2 aan");
    noteOn(0, 52, 64);
    MidiUSB.flush();
stopHammer = 3;  
  }  else{
    stopHammer = 99;   }
 
  delay(1); //onthaasten
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
