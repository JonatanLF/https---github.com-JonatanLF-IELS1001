#include <Adafruit_NeoPixel.h>

#define LED_COUNT 32
#define LED_PIN 2
#define potMeter A5

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

long j;
int pxlNr;
int i;
int dly = 0;

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);

void setup()
{
  Serial.begin(9600);
  strip.begin();
  pinMode(potMeter, INPUT);
  strip.setBrightness(80);
}

void lysfunk()
{
    for(i=0; i<LED_COUNT; i++){
        strip.setPixelColor(i, red);
        strip.show();
        dly = analogRead(potMeter);
        delay((dly+60)/6);
    }
    for(i=LED_COUNT-1; i>0; i--){
        strip.setPixelColor(i, green);
        strip.show();
        dly = analogRead(potMeter);
        delay((dly+60)/6);
    }
}

void regnbue()
{
    for(j=0; j<5*65536; j+=256){
        for(i=0; i<strip.numPixels(); i++){
            pxlNr = j+(i*65536L/strip.numPixels());
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pxlNr)));
        }
        strip.show();
        dly = analogRead(potMeter);
        delay((dly+80)/70);
    }
}
//Hei
void loop()
{
    //lysfunk();
    regnbue();
}
