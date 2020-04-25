#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

int threshold1 = 300;
int threshold2 = 800;
int threshold3 = 1300;

const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if (sensorValue < threshold1) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  } else {
    digitalWrite(ledPin1, HIGH);
    if (sensorValue < threshold2) {
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    } else {
      digitalWrite(ledPin2, HIGH);
      if (sensorValue < threshold3) {
        digitalWrite(ledPin3, LOW);
      } else {
        digitalWrite(ledPin3, HIGH);
      }
    }
  }
  delay(10);
}
