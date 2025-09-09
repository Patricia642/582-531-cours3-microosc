#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
CRGB monPixel;

#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires.
MicroOscSlip<128> monOsc(&Serial);



void setup() {
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);
  pinMode( MA_BROCHE_BOUTON , INPUT );
  Serial.begin(115200);
}

void loop() {
  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  monOsc.sendInt("/bouton", maLectureBouton);

  int maLectureAnalogique = analogRead( MA_BROCHE_ANGLE );
  monOsc.sendInt("/angle", maLectureAnalogique);


  //Serial.println(maLectureBouton);
  delay(100);

  monPixel = CRGB(0, millis() % 255, 0);
  FastLED.show();
}

