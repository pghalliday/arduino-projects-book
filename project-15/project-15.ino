const int optoPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(optoPin, OUTPUT);
}

void loop() {
  digitalWrite(optoPin, HIGH);
  Serial.println("On");
  delay(2000);
  digitalWrite(optoPin, LOW);
  Serial.println("Off");
  delay(2000);
}
