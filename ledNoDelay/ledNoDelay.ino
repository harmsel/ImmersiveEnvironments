#include <Adafruit_NeoPixel.h>
#include <elapsedMillis.h>
#define PIN 3
#define NUMPIXELS 13 // zoveel ledjes heeft je strip
elapsedMillis timeElapsed1;

int i = 0;

int volgendeEffect = 1;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();  // Set all pixel colors to 'off'
  Serial.begin(9600);
}

void loop() {
  delay(20); // maakt serial Print beter leesbaar

  if (volgendeEffect == 1) {
    ledsLopen (30, 2); //snelheid, volgende effect
    Serial.println(" 1 1 -- effect 1");
  }
  if (volgendeEffect == 2) {
    ledsTerugLopen (20, 1);
    Serial.println("effect 2");
  }
}


void ledsLopen (int snelheid, int next) {

  // Ledst lopen van 0 naar de laatste led met de ingestelde kleur
  if (timeElapsed1 > snelheid) {
    pixels.setPixelColor(i, pixels.Color(0, 50, 0));
    pixels.show();
    timeElapsed1 = 0;
    i++;
    if (i == NUMPIXELS) {
      volgendeEffect = next;
    }
  }
}

// ---- Ledst lopen van de vorige hoogst gehaalde LED terug naar nul
void ledsTerugLopen (int snelheid, int next) {
  if (timeElapsed1 > snelheid) {
    pixels.setPixelColor(i, pixels.Color(20, 0, 0));
    pixels.show();
    timeElapsed1 = 0;
    i--;
  }
  if (i == 0) {
    volgendeEffect = next;
  }
}
