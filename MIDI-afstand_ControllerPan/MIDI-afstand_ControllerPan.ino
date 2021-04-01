
#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);//dus op D7


void setup() {
  Serial.begin(115200);
}


void loop() {
  long afstand;
  afstand = ultrasonic.MeasureInCentimeters();
  Serial.print(afstand); Serial.println(" cm");
    int stand = afstand*2;
    controlChange(0, 10, stand);
    MidiUSB.flush();
 
  delay(50); //onthaasten
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
