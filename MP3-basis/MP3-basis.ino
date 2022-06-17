// Onderstaande code werkt met de Arduino UNO
// Download zip via: https://github.com/Seeed-Studio/Seeed_Serial_MP3_Player
// Installeer deze zip (Library) via Sketch > INstall Library
// De files op het SD kaartje moeten 0001.mp3, 0002.mp3, etc. heten


#include "KT403A_Player.h"
#include <SoftwareSerial.h> //maakt deze library beschikbaar binnen onderstaande code
SoftwareSerial SoftSerial(2, 3); // Sluit de MP3 speler aan op D3
KT403A<SoftwareSerial> MP3Player; //object mp3 player aanmaken

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  MP3Player.init(SoftSerial);
}

void loop() {
  Serial.println("Start het geluid");
  MP3Player.playSongMP3(2); //Speel het tweede geluid in de "MP3" folder af -> ./MP3/0002.wav
  delay (2000);
}
