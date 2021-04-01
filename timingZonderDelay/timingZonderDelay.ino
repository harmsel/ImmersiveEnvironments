#include <elapsedMillis.h>
elapsedMillis wachtFF;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (wachtFF > 500) {//om de hoeveel tijd moet de wekker afgaan?
    wachtFF = 0; //de wekker weer op 0 zetten
    Serial.println("die je ding"); // hier dus de code die je elke zoveel millis wilt uitvoeren
  }
}
