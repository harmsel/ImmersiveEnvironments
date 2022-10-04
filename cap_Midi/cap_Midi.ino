#include <CapacitiveSensor.h>
#include "MIDIUSB.h"

/* NOTES: 
noteOn(0, 36, 64);   // C2, normal velocity
noteOn(0, 26, 64);   // D1, normal velocity
noteOn(0, 28, 64);   // E1, normal velocity
noteOn(0, 29, 64);   // F1, normal velocity
noteOn(0, 31, 64);   // G1, normal velocity
*/

CapacitiveSensor cs_4_2 = CapacitiveSensor(12, 11);  // pin 11 yellow, pin 12 white. Black is the sensor wire
int losGeweest = true;

void setup() {
  //  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}

void loop() {
  long start = millis();
  long total1 = cs_4_2.capacitiveSensor(30);
  Serial.println(total1);  // print sensor output 1

  if (total1 > 10000 && losGeweest) {  //vooral lekker prutsen met die waarde van 1000, die bepaalt de gevoeligheid
    Serial.println("F1");
    noteOn(0, 41, 64);  // F1, normal velocity
    MidiUSB.flush();
    losGeweest = false;
  } else if (total1 < 3000 && !losGeweest) {
    losGeweest = true;
  }

  delay(20);  // arbitrary delay to limit data to serial port
}


/// --- functions ---------

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = { 0x09, 0x90 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = { 0x08, 0x80 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOff);
}
