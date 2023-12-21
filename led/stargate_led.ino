// https://arduino-france.site/bibliotheque-fastled/
#include "FastLED.h"

#define NUM_LEDS 9 // nombre de LEDs
#define PIN 4 // port de connexion ws2812b
int ledArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
CRGB leds[NUM_LEDS];
int randomLed ;

  int i, j = 0;

void setup() {
   FastLED.addLeds <WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
   FastLED.setBrightness(50);

   
}

void loop() {

  
  i = random(0, 8);
  
  if (ledArray[i] == 0) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(2000);
    ledArray[i] = 1;
    j++;
  } 


  if (j== 8) {
    delay(1000);
    for (i=0; i<9;i++) {
    leds[i] = CHSV(0, 255, 0);
    FastLED.show();
    delay(500);
    }
    j=0;
    for (i=0; i<9;i++) {
      ledArray[i] = 0;
    }
  }


}
