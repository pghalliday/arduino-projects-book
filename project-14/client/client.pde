import processing.serial.*;

Serial myPort;
PImage logo;

int bgcolor = 0;

void setup() {
  colorMode(HSB, 255);
  size(0, 0);
  surface.setResizable(true);
  logo = loadImage("http://arduino.cc/logo.png");
  surface.setSize(logo.width, logo.height);

  println("Available serial ports:");
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[5], 9600);
}

void draw() {
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
  }
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}
