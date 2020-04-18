const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int previousSwitchState = 0;
int led = 2;
long interval = 2000;
long flashInterval = 200;
int flashState = LOW;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  } 
  pinMode(switchPin, INPUT);
}

void debug(char* msg) {
  Serial.println(msg);
}

void debugInt(char* msg, int value) {
  Serial.print(msg);
  Serial.println(value);
}

void loop() {
  unsigned long currentTime = millis();

  if (led == 8) {
    // flash all the LEDs if complete
    if (currentTime - previousTime > flashInterval) {
      previousTime = currentTime;
      flashState = flashState == LOW ? HIGH : LOW;
      debugInt("Flash: ", flashState);
      for (int i = 2; i < 8; i++) {
        digitalWrite(i, flashState);
      }
    }
  } else {
    if (currentTime - previousTime > interval) {
      // set direction LEDs light up based on switch state
      int currentLed = switchState == 0 ? 9 - led : led;
      debugInt("Turn on LED: ", currentLed);
      previousTime = currentTime;
      digitalWrite(currentLed, HIGH);
      led++;
      if (led == 8) {
        debug("Start Flashing");
        flashState = HIGH;
      }
    }
  }

  switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState) {
    debugInt("New switchState: ", switchState);
    for (int i = 2; i < 8; i++) {
      digitalWrite(i, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }

  previousSwitchState = switchState;
}
