#include "Ultrasonic.h" // Instal Library "Grove ultrasonic ranger" by Seeed Studio)
Ultrasonic ultrasonic(D6); //Ultrasonic  D6

#include <Adafruit_NeoPixel.h>// Install "Adafruit_NeoPixel.h" via: Tools > Manage Libraies
#define PIN 4         // Ledstrip on D4
#define NUMPIXELS 60 // Nr of leds in the strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  Serial.begin(9600);       // Code om je serial monitor te gebruiken
  pixels.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();           // Zet alle pixels uit
  pixels.show();             // Turn OFF all pixels ASAP
  pixels.setBrightness(50);  // Set helderheid  (max = 255)
}


void loop() {
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);

  if (afstand < 5 ) {//
    ledjesAan(1);

  } else if (afstand < 10 ) {
    ledjesAan(20);

  }  else if (afstand < 15 ) {
    ledjesAan(40);
    
  }  else {
    pixels.clear();  // Set all pixel colors to 'off'
    pixels.show();  // Stuur bovenstaande pixel update naar de strip
  }



  delay(30);// om de serial monitor leesbaarder te maken
}

void ledjesAan(int pix) {
  pixels.clear();  // Set all pixel colors to 'off'
  pixels.setPixelColor(pix, pixels.Color(0, 150, 0));
  pixels.show();  // Stuur bovenstaande pixel update naar de strip
}
