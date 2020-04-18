const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void debug(char* msg) {
  Serial.println(msg);
}

void debugInt(char* msg, int value) {
  Serial.print(msg);
  Serial.println(value);
}

int toggle(int switchState, int previousSwitchState, int value, char* label) {
  if (switchState != previousSwitchState) {
    if (switchState == HIGH) {
      debugInt(label, !value);
      return !value;
    }
  }
  return value;
}

void setup() {
  Serial.begin(9600);
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);

  motorSpeed = analogRead(potPin) / 4;

  motorEnabled = toggle(onOffSwitchState, previousOnOffSwitchState, motorEnabled, "motorEnabled: ");
  previousOnOffSwitchState = onOffSwitchState;

  motorDirection = toggle(directionSwitchState, previousDirectionSwitchState, motorDirection, "motorDirection: ");
  previousDirectionSwitchState = directionSwitchState;

  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }
}
