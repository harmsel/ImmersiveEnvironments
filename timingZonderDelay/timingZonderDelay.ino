#include <elapsedMillis.h>
elapsedMillis wektijd;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (wektijd == 500) {//om de hoeveel tijd moet de wekker afgaan?
    wektijd = 0; //de wekker weer op 0 zetten
    Serial.println("TRINGGGGG TRINGGGG"); // hier dus de code die je elke zoveel millis wilt uitvoeren
  }
  delay(1); //zo is de serial monitor beter leesbaar
}
