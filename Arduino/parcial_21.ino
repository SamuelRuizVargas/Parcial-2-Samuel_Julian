#include <Adafruit_NeoPixel.h>

#define LED_PIN 2

#define LED_COUNT 160

Adafruit_NeoPixel N1(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  N1.begin();
  
  for (int i=0;i<LED_COUNT;i++)
  {
    N1.setPixelColor(i, 20, 0, 255);
    N1.show(); // Initialize all pixels to 'off'
  }
}

void loop()
{
  
}