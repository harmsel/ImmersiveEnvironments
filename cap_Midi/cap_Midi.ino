#include <CapacitiveSensor.h>
#include "MIDIUSB.h"

//50K - 50M tussen de pinnen. weerstend. Hoe groter des te gevoeliger
CapacitiveSensor   sensCap = CapacitiveSensor(11, 13);       // pin 13 is de sensor


void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

int losGeweest = true;

void setup()
{
  //sensCap.set_CS_AutocaL_Millis(0xFFFFFFFF);     // zet autocalibrate uit (elke 20 seconden)
  Serial.begin(9600);
}

void loop()
{
  long start = millis();
  long total1 =  sensCap.capacitiveSensor(30);


  Serial.println(losGeweest);       
  Serial.println(total1);                  //  sensor output

  if (total1 > 1000 && losGeweest) { //vooral lekker prutsen met die waarde van 1000, die bepaalt de gevoeligheid
    Serial.println("C3");
    noteOn(0, 60, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(100);
    losGeweest = false;
  } else if (!losGeweest) {
    Serial.println("C2");
    noteOn(0, 48, 64);   // Channel 0, C3, normal velocity
    MidiUSB.flush();
    delay(100);
 losGeweest = true;
  }


  delay(20); //gewoon omdat het leven al snel genoeg gaat
}
