#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"

#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556
#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278
#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 112

MeRGBLed rgb;
MeBuzzer buzzer;
void setup()
{
  rgb.clear();
  rgb.setNumber(16);
  rgb.clear();
  rgb.setColor(10, 0, 0);
  buzzer.tone(NTD1, 300); 
  delay(300);
  rgb.setColor(0, 10, 0);
  buzzer.tone(NTD2, 300);
  delay(300);
  rgb.setColor(0, 0, 10);
  buzzer.tone(NTD3, 300);
  delay(300);
  rgb.clear();
  Serial.begin(115200);
  buzzer.noTone();
}

int r = 0, g = 0, b = 0, s=0;
void loop()
{
  rgb.setColorAt (1, r,g,b);
  rgb.show();
  switch (s) {
    case 0: b--; r++; if (r>25) { b=0; r--; s=1; } break;
    case 1: r--; g++; if (g>25) { r=0; g--; s=2; } break;
    case 2: g--; b++; if (b>25) { g=0; b--; s=0; } break;
  }
  delay(40);
}
