#include "MIDIUSB.h"

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);}

int teller = 0; //teller aanmaken
bool geraakt = false; 

void setup()
{
  Serial.begin(9600);
}

void loop(){


  /* ---------------- Maak contact ----------- */

  int waarde = analogRead(A1);
  Serial.println(waarde);
  if (waarde < 100 && geraakt == false) { //vooral lekker prutsen met
    teller = teller + 1;
    geraakt = true;
    delay(1000);
  } else {
   geraakt = false;
  }

  /// ------ het tellen van de slagen, elke succesvollle slag een andere scene
  if (teller == 1) {
    Serial.println("C2 Sending note on");
    noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
  } else if ( teller == 2) {
  Serial.println("C3 Sending note on");
    noteOn(0, 60, 64);   // Channel 0, C3, normal velocity
    MidiUSB.flush();
    delay(1000);
  } else if ( teller == 3) {
  Serial.println("C?? Sending note on");
    noteOn(0, 70, 64);   // Channel 0, C3, normal velocity
    MidiUSB.flush();
    delay(1000);
  } else if (teller >3 ){

   teller = 0; //Reset de teller
  }

  delay(20); //gewoon omdat het leven al snel genoeg gaat
}
