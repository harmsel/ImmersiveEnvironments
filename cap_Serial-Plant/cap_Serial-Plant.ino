#include <CapacitiveSensor.h> .///install library by Paul


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

  delay(20);  // arbitrary delay to limit data to serial port
}

