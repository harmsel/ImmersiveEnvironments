
#include "MIDIUSB.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(4);//dus op D4


int afstandOld; //Nodig
int offset = 5; //offset tussen de bewegingen CM
int vol=0;

void setup() {
  Serial.begin(115200);
}


void loop() {
  long afstand;
  afstand = ultrasonic.MeasureInCentimeters();
 // Serial.print(afstand); Serial.println(" cm");
  int stand = afstand;
    Serial.println(vol);

  if ((afstand > afstandOld + offset || afstand < afstandOld - offset) && vol <150) {
    Serial.println("Harde dansers in de House!!");
    vol=vol+5;


    
    afstandOld = afstand;
    delay(20); //tussen metingen
  } else if (vol >0){
    
    vol=vol-1;
    
    }

  delay(30); //onthaasten
}
