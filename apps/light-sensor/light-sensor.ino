#define ALS A6

void setup() {
  // pinMode (PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x6 = analogRead(A6);
  Serial.print (x6);
  Serial.print ("\n");
  delay (100);
}
