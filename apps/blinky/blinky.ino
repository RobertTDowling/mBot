#define PIN 13 // Blue LED

void setup() {
  pinMode (PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN, 1^digitalRead (PIN));
  delay (100);
}
