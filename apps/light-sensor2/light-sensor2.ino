// As this is tuned, this is very sensitive to changes.  It take about 5-10
// samples to converge on and recognize a new steady state (good).  It will
// immediately discover an unsteady state (!good).

#define ALS A6

#include "FEmv.h"
#include "Stats.h"

#define ALPHA 1/20.
#define USE_STD 0

// Problems with using STD and v2 < v1 / 2 (or other small divisor)
// 1) it does not reject when things change.  It takes a few samples to decide
// things aren't "good" so you get some high readings in v1 mixed into v2
// 2) it does not stably detect good when v1 is around 0.50
// Problems with not using STD
// 1) Variance is much bigger than std when >1, so it takes a long time to
// converge
// Using v2 < v1 works good, and the post-process into stdev seems acceptable,
// at least for v1

FEmv emv1(ALPHA), emv2(ALPHA), emv3(1/4.0);
CStats avg;

void setup() {
  Serial.begin(115200);
}

// int16_t d=0;
bool good=false, lgood=false;
CStats stats;

// USE_STD: 40 is 12ms. 100 is 30ms. 55 is 16.6ms = 60Hz
// not STD: 55 is 12ms. 100 is 23ms. 72 is 16.6ms = 60Hz
#define SAMPLE 60

void loop() {
  int i;
  int16_t x;
  float v1, v2;
  avg.Init ();
  long t0 = millis();
  for (i=0; i<SAMPLE; i++) {
    x = analogRead(A6);
    // Serial.print (x<d ? '-' : ' ');
    // int16_t j = abs(x-d);  d=x;
    // j ? Serial.print (j) : Serial.print (' ');
    v1 = (emv1.filter (x));
    v2 = (emv2.filter (v1));
    avg.Add(x);
  }
  // Make decision
  lgood = good;
  good = v2 < v1;
  float s1 = sqrt(v1), s2 = sqrt(v2);
  long t1 = millis();
  // Serial.print (" : ");
  Serial.print (avg.Mean(),0);
  Serial.print (" ");
  Serial.print (avg.Range(),0);
  Serial.print (" ");
  Serial.print (s1);
  Serial.print (" ");
  Serial.print (s2);
  Serial.print (" ");
  Serial.print (t1-t0);
  if (good && !lgood) {
    stats.Init();
    emv3.Init();
  }
  if (good) { 
    stats.Add (s1);
    float y = emv3.filter(s1);
    Serial.print ("  *** ");
    Serial.print (stats.Min());
    Serial.print ('/');
    Serial.print (stats.Mean());
    Serial.print ('/');
    Serial.print (stats.Max());
    Serial.print (" N=");
    Serial.print (stats.N());
    Serial.print (" ema:");
    Serial.print (emv3.mean());
  }
  Serial.print ("\n");
  delay (500);
}
