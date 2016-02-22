#define s2 A3

void setup() {
  Serial.begin(9600);
}

void loop() {
    pinMode (s2, OUTPUT);
    digitalWrite(s2,LOW);
    delayMicroseconds(2);
    digitalWrite(s2,HIGH);
    delayMicroseconds(10);
    digitalWrite(s2,LOW);
    pinMode(s2,INPUT);
    long duration = pulseIn(s2,HIGH,500000);

    Serial.println (duration);
    delay (500);
}
