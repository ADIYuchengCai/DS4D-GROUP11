#include <Adafruit_NeoPixel.h>

#define PIN1 12
#define PIN2 6
#define NUMPIXEL 11   //how many pixel on the strip1.

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXEL, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXEL, PIN2, NEO_GRB + NEO_KHZ800);

unsigned long time_1 = 0;
unsigned long time_2 = 0;


int MinBrightness = 0;       //value 0-255
int MaxBrightness = 100;      //value 0-255

//int numLoops1 = 2;
//int numLoops2 = 1;
//int numLoops3 = 5;
//int numLoops4 = 3;          //add new integer and value for more color's loop if needed.

int fadeInWait = 5;          //lighting up speed, steps.
int fadeOutWait = 0;         //dimming speed, steps.

int fadeInWait2 = 0;          //lighting up speed, steps.
int fadeOutWait2 = 5;         //dimming speed, steps.
//---------------------------------------------------------------------------------------------------//

void setup() {



  
  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
}

/*
rgbBreathe(strip1.Color(insert r,g,b color code),numLoops(refer to integer above), (duration for lights to hold before dimming. insert 0 to skip hold)
rainbowBreathe(numLoops(refer to integer above),(duration for lights to hold before dimming. insert 0 to skip hold)
*/

void loop() {
  
  //---strip1 will stay lit for some time before dimming again.----
 //digitalWrite(12, HIGH);
 strip1.setBrightness(255);
 strip1.setPixelColor(0, 255,0,0);
 strip1.show();
  //rgbBreathe(strip1.Color(255, 0, 0), strip2.Color(0, 255, 0),numLoops1, 10,10); //red.
  //rainbowBreathe(numLoops2, 250);
//rgbBreathe2(strip2.Color(0, 255, 0), numLoops1, 50); //green.
  //duplicate for more colors.
}


//Functions -----------------------------------------------------------------------------------------//


void rgbBreathe(uint32_t c1,uint32_t c2, uint8_t x, uint8_t y1, uint8_t y2) {

    for (uint8_t b = MinBrightness; b < MaxBrightness; b++) {
      strip1.setBrightness(b * 255 / 255);
      for (uint16_t i = 0; i < strip1.numPixels(); i++) {
        strip1.setPixelColor(i, c1);
      }
      strip1.show();
      //digitalWrite(12,HIGH);
      
      //delay(fadeInWait);

      
    }

    for (uint8_t b = MinBrightness; b < MaxBrightness; b++) {
      strip2.setBrightness(b * 255 / 255);
      for (uint16_t i = 0; i < strip2.numPixels(); i++) {
        strip2.setPixelColor(i, c2);
      }
      strip2.show();
      //digitalWrite(6,HIGH);
      delay(fadeInWait2);
    }

    
    strip1.setBrightness(MaxBrightness * 255 / 255);
    strip2.setBrightness(MaxBrightness * 255 / 255);
    
    for (uint16_t i = 0; i < strip1.numPixels(); i++) {
      strip1.setPixelColor(i, c1);
      
      strip1.show();
      //digitalWrite(12,HIGH);
      delay(y1);
    }
     for (uint16_t i = 0; i < strip2.numPixels(); i++) {
      
      strip2.setPixelColor(i, c2);
    strip2.show();
    //digitalWrite(6,HIGH);
     
      
      delay(y2);
    }
    
    for (uint8_t b = MaxBrightness; b > MinBrightness; b--) {
      strip1.setBrightness(b * 255 / 255);
      
      for (uint16_t i = 0; i < strip1.numPixels(); i++) {
        strip1.setPixelColor(i, c1);
        
      }
     strip1.show();
      //digitalWrite(12,HIGH);
      delay(fadeOutWait);
    }
 for (uint8_t b = MaxBrightness; b > MinBrightness; b--) {
      strip2.setBrightness(b * 255 / 255);
      for (uint16_t i = 0; i < strip1.numPixels(); i++) {
        strip2.setPixelColor(i, c2);
      }

      strip2.show();
      //digitalWrite(6,HIGH);
      delay(fadeOutWait2);
    }
    
  }




void rainbowBreathe(uint8_t x, uint8_t y) {
  for (int j = 0; j < x; j++) {
    for (uint8_t b = MinBrightness; b < MaxBrightness; b++) {
      strip1.setBrightness(b * 255 / 255);
      for (uint8_t i = 0; i < strip1.numPixels(); i++) {
        strip1.setPixelColor(i, Wheel(i * 256 / strip1.numPixels()));
      }
      strip1.show();
      delay(fadeInWait);
    }
    strip1.setBrightness(MaxBrightness * 255 / 255);
    for (uint8_t i = 0; i < strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel(i * 256 / strip1.numPixels()));
      strip1.show();
      delay(y);
    }
    for (uint8_t b = MaxBrightness; b > MinBrightness; b--) {
      strip1.setBrightness(b * 255 / 255);
      for (uint8_t i = 0; i < strip1.numPixels(); i++) {
        strip1.setPixelColor(i, Wheel(i * 256 / strip1.numPixels()));
      }
      strip1.show();
      delay(fadeOutWait);
    }
  }
}


//NeoPixel Wheel for Rainbow---------------------------------------

uint32_t Wheel(byte WheelPos) {
  WheelPos = 140 - WheelPos;       //the value here means - for 255 the strip1 will starts with red, 127-red will be in the middle, 0 - strip1 ends with red.
  if (WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
