#include "MIDIUS.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(13);  //Yellow pin 
// Connect the Black wire to GND, Red 5V (see readme ))

bool triggered = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long distance = ultrasonic.MeasureInCentimeters();
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 50) {
    int angle = distance * 3;    // change the number, higher is shorter range
    controlChange(0, 10, angle);  // controll
    MidiUSB.flush();
    Serial.print("angle: ");
    Serial.println(angle);
  } else if (distance < 100 && !triggered){
    Serial.println("C2");
    noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    triggered = true;
  } else if (distance > 150){
    triggered = false;
    }
  delay(150);  //onthaasten
}

// -- hieronder de functies nodig voor MIDI
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