/*
  speciaal gemaakt voor de fijne studenten van de Minor Immersive Environments CMD
  Onderstaande code stuurt een MIDI signaal 'Controll Change' naar de laptop
  aan de hand van de afstand tot een afstandsensor.
  Gebruikte hardware: Arduino Micro
*/

#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(13);//Pin 13

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT); //Button Pin 12!
}


void loop() {
  // -- drukknopje, geluid starten ----

  if (digitalRead(12) == LOW) {
    Serial.println("C2");
    noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();

  } else {
    //Serial.println("niet ingedrukt");
  }

  // -- afstandsensor, effect aanpassen adhv de afstand ---------

  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.print(afstand); Serial.println(" cm");
  if (afstand < 50) { // alleen uitvoeren als er iets in de buurt van sensor zit
    int stand = -afstand * 3 ;
    controlChange(0, 10, stand);
    MidiUSB.flush();
  }

  delay(150); //onthaasten
}


// -- hieronder de functies nodig voor MIDI
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
