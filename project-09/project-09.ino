const int motorPin = 9;
const int potPin = A0;
int potVal = 0;
int motorSpeed = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  motorSpeed = map(potVal, 0, 1023, 0, 255);
  analogWrite(motorPin, motorSpeed);
}
