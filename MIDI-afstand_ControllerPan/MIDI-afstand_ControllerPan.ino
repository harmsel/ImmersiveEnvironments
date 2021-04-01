
#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);//dus op D7


void setup() {
  Serial.begin(115200);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {
  long afstand;
  afstand = ultrasonic.MeasureInCentimeters();
  Serial.print(afstand); Serial.println(" cm");

  /// ---  als de afstand minder is dan zoveel cm zet geluid 1 aan
  if (afstand < 2) {
    Serial.println("E2 aan");
    noteOn(0, 48, 64);
    MidiUSB.flush();
  }
  else if (afstand < 5) {
    Serial.println("D2 aan");
    noteOn(0, 50, 64);
    MidiUSB.flush();
  }
  else if (afstand < 10) {
    Serial.println("C2 aan");
    noteOn(0, 52, 64);
    MidiUSB.flush();
  } else if (afstand > 30 && afstand < 50) {
    int stand = ((afstand/2) - 30)*6.5;
    controlChange(0, 10, stand);
    MidiUSB.flush();
  }  else{
    //Doe niks
  }
 
  delay(20); //onthaasten
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
