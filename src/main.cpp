#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 10
#define BRIGHTNESS 30
#define UPDATES_PER_SECOND 100

CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType currentBlending;

void FillLEDsFromPaletteColors( uint8_t colorIndex);

void setup() {
    delay(1000);
    Serial.begin(9600);
    FastLED.addLeds < WS2812, LED_PIN, GRB > (leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

void loop() {

    static uint8_t startIndex = 0;
    startIndex++;

    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors( uint8_t colorIndex){
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}
