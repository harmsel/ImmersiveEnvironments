/*
   Made for the amazing student attending the Minor Immersive Environments
   by Harm

   This code will read the distance sensor and will trigger a MIDI node just
   ones when the distance is changed by 10 cm.
*/

#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);

int oldVal;

int running1 =  false;
int running2 =  false;
int running3 =  false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long RangeInCentimeters; //var
  int cm = ultrasonic.MeasureInCentimeters();

  // Make the sensor les sensitive to prevent trigger when distance
  // did not realy change a lot.
  int sensorVal = cm / 20; //feel free to change the number

  //Serial.println(sensorVal);                  //  sensor output

  if (sensorVal < 1 && sensorVal != oldVal && !running1) { // distance in Decimeters!
    Serial.println("C1");
    noteOn(0, 24, 64);   // C1, normal velocity
    MidiUSB.flush();
    running1 =  true;
    running2 =  false;
    running3 =  false;

  }  else if (sensorVal < 2 && sensorVal != oldVal && !running2) { // distance in Decimeters!
    Serial.println("C2");
    noteOn(0, 36, 64);   //  C2, normal velocity
    MidiUSB.flush();
    running1 =  false;
    running2 =  true;
    running3 =  false;


  } else if (sensorVal < 3 && sensorVal != oldVal && !running3 ) { // distance in Decimeters!
    Serial.println("C3");
    noteOn(0, 48, 64);   // C3, normal velocity
    MidiUSB.flush();
    running1 =  false;
    running2 =  false;
    running3 =  true;

  }
  oldVal = sensorVal;

  delay(20); //delay for the ultr sensor
}



void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
