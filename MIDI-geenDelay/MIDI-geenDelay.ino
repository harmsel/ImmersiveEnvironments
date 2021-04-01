#include <CapacitiveSensor.h>
#include "MIDIUSB.h"
#include <elapsedMillis.h>
elapsedMillis wachtFF1;
elapsedMillis wachtFF2;
elapsedMillis wachtFF3;
int wachtTijd = 500;

//50K - 50M tussen de pinnen. weerstand. Hoe groter des te gevoeliger
CapacitiveSensor   sensCap = CapacitiveSensor(11, 13);       // pin 13 is de sensor


void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controllChange(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}


void setup()
{
  //sensCap.set_CS_AutocaL_Millis(0xFFFFFFFF);     // zet autocalibrate uit (elke 20 seconden)
  Serial.begin(9600);
}

void loop(){
  long start = millis();
  long sensorWaarde =  sensCap.capacitiveSensor(30);

  Serial.print(millis() - start);        // performance in milliseconds
  Serial.println(sensorWaarde);                  //  sensor output

  if (sensorWaarde > 1000) { //gevoeligheid
        Serial.println("C2");
    noteOn(0, 48, 64);   
    MidiUSB.flush();
    if (wachtFF1 > wachtTijd) {
      wachtFF1 = 0; //de wekker weer op 0 zetten
      noteOff(0, 48, 64); 
      MidiUSB.flush();
    }

  } else if (sensorWaarde > 600) {//gevoeligheid
    Serial.println("C3");
    noteOn(0, 60, 64);   
    MidiUSB.flush();

    if (wachtFF2 > wachtTijd) {
      wachtFF2 = 0; //de wekker weer op 0 zetten
      noteOff(0, 60, 64);  // Channel 0, middle C, normal velocity
      MidiUSB.flush();
    }

  } else {
    Serial.println("c4");
    noteOn(0, 63, 64); 
    MidiUSB.flush();
    if (wachtFF3 > wachtTijd) {
      wachtFF3 = 0; //de wekker weer op 0 zetten
      noteOff(0, 63, 64);  
      MidiUSB.flush();
    }
  }
}