// A non-blocking everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN_1    3
#define LED_PIN_2    4
#define LED_PIN_3    5
#define LED_PIN_4    6
#define LED_PIN_5    7
#define LED_PIN_6    8

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 12

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip1(LED_COUNT, LED_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, LED_PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(LED_COUNT, LED_PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(LED_COUNT, LED_PIN_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5(LED_COUNT, LED_PIN_5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6(LED_COUNT, LED_PIN_6, NEO_GRB + NEO_KHZ800);


// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
int           pixelNumber=LED_COUNT;

unsigned long pixelPrevious_1 = 0;    
unsigned long pixelCurrent_1 = 0;         // Previous Pixel Millis
int           pixelInterval_1 = 40;       // Pixel Interval (ms)
int           pixelBrightness_1=0 ;       // Pixel Interval (ms)
int           record_1=0;



unsigned long pixelPrevious_2 = 0; 
unsigned long pixelCurrent_2 = 0; // Previous Pixel Millis
int           pixelInterval_2 = 80;       // Pixel Interval (ms)
int           pixelBrightness_2=0 ;       // Pixel Interval (ms)
int           record_2=0;

unsigned long pixelPrevious_3 = 0; 
unsigned long pixelCurrent_3= 0;            // Previous Pixel Millis
int           pixelInterval_3 = 200;       // Pixel Interval (ms)
int           pixelBrightness_3=0;       // Pixel Interval (ms)
int           record_3=0;

unsigned long pixelPrevious_4 = 0; 
unsigned long pixelCurrent_4= 0;            // Previous Pixel Millis
int           pixelInterval_4 = 200;       // Pixel Interval (ms)
int           pixelBrightness_4=0;       // Pixel Interval (ms)
int           record_4=0;


unsigned long pixelPrevious_5 = 0; 
unsigned long pixelCurrent_5= 0;            // Previous Pixel Millis
int           pixelInterval_5 = 210;       // Pixel Interval (ms)
int           pixelBrightness_5=0;       // Pixel Interval (ms)
int           record_5=0;

unsigned long pixelPrevious_6 = 0; 
unsigned long pixelCurrent_6= 0;            // Previous Pixel Millis
int           pixelInterval_6 = 40;       // Pixel Interval (ms)
int           pixelBrightness_6=0;       // Pixel Interval (ms)
int           record_6=0;


// setup() function -- runs once at startup --------------------------------
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
Serial.begin(9600);
  strip1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip1.show();            // Turn OFF all pixels ASAP
  //strip1.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

   strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();            // Turn OFF all pixels ASAP
  //strip2.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  strip3.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip3.show();            // Turn OFF all pixels ASAP

  strip4.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip4.show();            // Turn OFF all pixels ASAP


  strip5.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip5.show();            // Turn OFF all pixels ASAP

  strip6.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip6.show();            // Turn OFF all pixels ASAP
}

// loop() function -- runs repeatedly as long as board is on ---------------
void loop() {
  unsigned long currentMillis = millis();                     //  Update current time
 // if((currentMillis - patternPrevious_1) >= patternInterval_1) {  //  Check for expired time
  //  patternPrevious_1 = currentMillis;
    
 // }
  
  if(currentMillis - pixelPrevious_1 >= pixelInterval_1) {        //  Check for expired time
    pixelPrevious_1 = currentMillis;                            //  Run current frame
    colorWipe1(strip1.Color(68,211,10),pixelInterval_1);
    //Serial.print(pixelPrevious_1);
  }
  
   if(currentMillis - pixelPrevious_2 >= pixelInterval_2) {        //  Check for expired time
    pixelPrevious_2 = currentMillis;                            //  Run current frame
    colorWipe2(strip2.Color(68,211,10),pixelInterval_2);
    //Serial.print(pixelPrevious_2);
  }

    if(currentMillis - pixelPrevious_3 >= pixelInterval_3) {        //  Check for expired time
    pixelPrevious_3 = currentMillis;                            //  Run current frame
    colorWipe3(strip3.Color(68,211,10),pixelInterval_3);
  }

    if(currentMillis - pixelPrevious_4 >= pixelInterval_4) {        //  Check for expired time
    pixelPrevious_4 = currentMillis;                            //  Run current frame
    colorWipe4(strip4.Color(68,211,10),pixelInterval_4);
  } 
    if(currentMillis - pixelPrevious_5 >= pixelInterval_5) {        //  Check for expired time
    pixelPrevious_5 = currentMillis;                            //  Run current frame
    colorWipe5(strip5.Color(255,14,0),pixelInterval_5);
  } 

    if(currentMillis - pixelPrevious_6 >= pixelInterval_6) {        //  Check for expired time
    pixelPrevious_6 = currentMillis;                            //  Run current frame
    colorWipe6(strip6.Color(255,14,0),pixelInterval_6);
  } 
}

// Some functions of our own for creating animated effects -----------------

 // Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe1(uint32_t color, int wait) {
  if(pixelInterval_1 != wait)
    pixelInterval_1 = wait;                   //  Update delay time
  for(int i=0;i<pixelNumber;i++)
  strip1.setPixelColor(i, color); //  Set pixel's color (in RAM)
  
  strip1.setBrightness(pixelBrightness_1);         //设定一个每次循环自减的量
                               //  Update strip to match

  if(pixelBrightness_1 >= 240)           //  Loop the pattern from the first LED
    record_1=1;
if(pixelBrightness_1 <= 5)           //  Loop the pattern from the first LED
    record_1=0;

    
  if(record_1==0)
  {
  pixelBrightness_1 += 20;
  //Serial.print(pixelBrightness_1);
  }
  else if(record_1==1)
  pixelBrightness_1 -= 20;

  
  //  Advance current pixel



//Serial.println(pixelBrightness_1);

strip1.show();
//delay(50);
  
  //if(pixelCurrent_1 >= pixelNumber)           //  Loop the pattern from the first LED
  //  pixelCurrent_1 = 0;
}

void colorWipe2(uint32_t color, int wait) {
  if(pixelInterval_2 != wait)
    pixelInterval_2 = wait;                   //  Update delay time
    
  for(int i=0;i<pixelNumber;i++)
  strip2.setPixelColor(i, color); //  Set pixel's color (in RAM)
  strip2.setBrightness(pixelBrightness_2);         //设定一个每次循环自减的量
                              //  Update strip to match
  
if(pixelBrightness_2 >= 240)           //  Loop the pattern from the first LED
    record_2=1;
if(pixelBrightness_2 <= 10)           //  Loop the pattern from the first LED
    record_2=0;
    
  if(record_2==0)
  pixelBrightness_2 += 20;
  else if(record_2==1)
  pixelBrightness_2 -= 20;

strip2.show(); 
}


void colorWipe3(uint32_t color, int wait) {
  if(pixelInterval_3 != wait)
    pixelInterval_3 = wait;                   //  Update delay time
    
  for(int i=0;i<pixelNumber;i++)
  strip3.setPixelColor(i, color); //  Set pixel's color (in RAM)
  strip3.setBrightness(pixelBrightness_3);         //设定一个每次循环自减的量
                              //  Update strip to match
  
if(pixelBrightness_3 >= 240)           //  Loop the pattern from the first LED
    record_3=1;
if(pixelBrightness_3 <= 10)           //  Loop the pattern from the first LED
    record_3=0;
    
  if(record_3==0)
  pixelBrightness_3 += 20;
  else if(record_3==1)
  pixelBrightness_3 -= 20;

strip3.show(); 
}


void colorWipe4(uint32_t color, int wait) {
  if(pixelInterval_4 != wait)
    pixelInterval_4 = wait;                   //  Update delay time
    
  for(int i=0;i<pixelNumber;i++)
  strip4.setPixelColor(i, color); //  Set pixel's color (in RAM)
  strip4.setBrightness(pixelBrightness_4);         //设定一个每次循环自减的量
                              //  Update strip to match
  
if(pixelBrightness_4 >= 240)           //  Loop the pattern from the first LED
    record_4=1;
if(pixelBrightness_4 <= 10)           //  Loop the pattern from the first LED
    record_4=0;
    
  if(record_4==0)
  pixelBrightness_4 += 20;
  else if(record_4==1)
  pixelBrightness_4 -= 20;

strip4.show(); 
}


void colorWipe5(uint32_t color, int wait) {
  if(pixelInterval_5 != wait)
    pixelInterval_5 = wait;                   //  Update delay time
    
  for(int i=0;i<pixelNumber;i++)
  strip5.setPixelColor(i, color); //  Set pixel's color (in RAM)
  strip5.setBrightness(pixelBrightness_5);         //设定一个每次循环自减的量
                              //  Update strip to match
  
if(pixelBrightness_5 >= 240)           //  Loop the pattern from the first LED
    record_5=1;
if(pixelBrightness_5 <= 10)           //  Loop the pattern from the first LED
    record_5=0;
    
  if(record_5==0)
  pixelBrightness_5 += 20;
  else if(record_5==1)
  pixelBrightness_5 -= 20;

strip5.show(); 
}


void colorWipe6(uint32_t color, int wait) {
  if(pixelInterval_6 != wait)
    pixelInterval_6 = wait;                   //  Update delay time
    
  for(int i=0;i<pixelNumber;i++)
  strip6.setPixelColor(i, color); //  Set pixel's color (in RAM)
  strip6.setBrightness(pixelBrightness_6);         //设定一个每次循环自减的量
                              //  Update strip to match
  
if(pixelBrightness_6 >= 240)           //  Loop the pattern from the first LED
    record_6=1;
if(pixelBrightness_6 <= 10)           //  Loop the pattern from the first LED
    record_6=0;
    
  if(record_6==0)
  pixelBrightness_6 += 20;
  else if(record_6==1)
  pixelBrightness_6 -= 20;

strip6.show(); 
}
