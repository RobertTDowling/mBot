#include "Stats.h"

#define PERIOD 1
#define REPORT_SIZE 1000
#define CHANNELS 8
#define DEBUG 0

int channel[] = { A0, A1, A2, A3, A4, A5, A6, A7 };

CStats s[CHANNELS];
char printbuf[1024];

#if DEBUG
int j=0;
#endif

void setup() {
	Serial.begin(115200);
}


void loop() {
	long t0 = millis();
	while (1) {
		// Wait for next sample time
		long t1 = millis();
		while (t1 - t0 < PERIOD) {
			t1 = millis();
		}
		t0 = t1;

		// Read channels
		int i;
		for (i=0; i<CHANNELS; i++) {
			int x = analogRead (channel[i]);
			s[i].Add (x);
#if DEBUG			
			if (j<10) {
				sprintf (printbuf, " %5d", x);
				Serial.print (printbuf);
			}
		}
		if (j<10) 
			Serial.println ("");
		j++;
#else
		}
#endif
		// Time to report?
		if (s[0].N() == REPORT_SIZE) {
			// write all this stuff
			Serial.print ("Mean:");
			for (i=0; i<CHANNELS; i++) {
				sprintf (printbuf, " %5d", (int) (s[i].Mean() +0.5));
				Serial.print (printbuf);
			}
			Serial.println ("");
			Serial.print ("Std: ");
			for (i=0; i<CHANNELS; i++) {
				float std = s[i].Stdev();
				int whole = (int)std;
				int frac = 100 * (std - whole);
				sprintf (printbuf, " %2d.%02d", whole, frac);
				Serial.print (printbuf);
			}
			Serial.println ("");
			Serial.println ("");

			// Clear out stats data
			for (i=0; i<CHANNELS; i++) {
				s[i].Init ();
			}
#if DEBUG
			j=0;
#endif
		}
	}
}
