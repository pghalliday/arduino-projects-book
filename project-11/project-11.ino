#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
const int smileyChar = 0;
const int unsmileyChar = 1;
int switchState = 0;
int previousSwitchState = 0;
int reply;

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte unsmiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
};

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.createChar(smileyChar, smiley);
  lcd.createChar(unsmileyChar, unsmiley);
  lcd.setCursor(0, 0);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);
      switch (reply) {
        case 0:
          lcd.print("Yes ");
	  lcd.write(byte(smileyChar));
          break;
        case 1:
          lcd.print("Most likely ");
	  lcd.write(byte(smileyChar));
          break;
        case 2:
          lcd.print("Certainly ");
	  lcd.write(byte(smileyChar));
          break;
        case 3:
          lcd.print("Outlook good ");
	  lcd.write(byte(smileyChar));
          break;
        case 4:
          lcd.print("Unsure ");
	  lcd.write(byte(unsmileyChar));
          break;
        case 5:
          lcd.print("Ask again ");
	  lcd.write(byte(unsmileyChar));
          break;
        case 6:
          lcd.print("Doubtful ");
	  lcd.write(byte(unsmileyChar));
          break;
        case 7:
          lcd.print("No ");
	  lcd.write(byte(unsmileyChar));
          break;
      }
    }
  }
  previousSwitchState = switchState;
}
