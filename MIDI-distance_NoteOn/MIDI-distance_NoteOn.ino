#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(13);  //plug in 4
int stopHammer = 999;

void setup() {
  Serial.begin(115200);
}

void loop() {
  long distance;
  distance = ultrasonic.MeasureInCentimeters();
  Serial.print(distance); Serial.println(" cm");

  /// ---  if  distance is 2 to 10 cm, send note E2. Just one time (stopHammer)
  if (distance > 2 && distance < 10 && stopHammer != 1) {
    Serial.println("1. ---- note E2 aan");
    noteOn(0, 48, 64);
    MidiUSB.flush();
    stopHammer = 1;
    // pre
  } else if (distance > 10 && distance < 15 && stopHammer != 2) {
    Serial.println("note D2 aan");
    noteOn(0, 50, 64);
    MidiUSB.flush();
    stopHammer = 2;
  } else if (distance > 15 && stopHammer != 3) {
    Serial.println(" -- note C2 aan");
    noteOn(0, 52, 64);
    MidiUSB.flush();
    stopHammer = 3;
  }
 // Serial.println(stopHammer);
  delay(50);  //onthaasten
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