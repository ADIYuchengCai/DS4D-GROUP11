#include <Adafruit_NeoPixel.h>

#define LED_PIN_1    6
#define LED_PIN_2   12
#define LED_COUNT 12

int   Fre_1=2;
int   Fre_2=3;
int Brightness_1=0;
int Brightness_2=0;
int pixelNumber=12;
Adafruit_NeoPixel strip1(LED_COUNT, LED_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, LED_PIN_2, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  strip1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip1.show();            // Turn OFF all pixels ASAP
  strip1.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

   strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();            // Turn OFF all pixels ASAP
  strip2.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // put your main code here, to run repeatedly:
for(int x=0;x<255;x++)
{

  
  Brightness_1=x%Fre_1*(255-10)+10;
  Brightness_2=x%Fre_2*(255-10)+10;
  strip1.setBrightness(Brightness_1);
  strip2.setBrightness(Brightness_2);
 
for(int i=0;i<pixelNumber;i++)
{
  strip1.setPixelColor(i,255,0,0);
  strip2.setPixelColor(i,0,255,0);
  
  }
  
  strip1.show();
  strip2.show();
  delay(100);

  
  
  
  
  }
}
