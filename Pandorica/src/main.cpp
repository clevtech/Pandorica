#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>               // Library to use I2C to display
#include "SSD1306Wire.h"        // Display library

static const int servoPin = 12;
int GRN = 4;
SSD1306Wire  display(0x3c, 5, 4);

Servo servo1;

void setup() {
    Serial.begin(115200);
    pinMode(GRN, OUTPUT);
    display.init();
    display.flipScreenVertically();
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Kazdream Technologies");
    display.drawString(0, 10, "Cleverest Technologies");
    display.drawString(0, 20, "Project: Pandorica");
    display.drawString(0, 30, "No usb");
    display.display();
    servo1.attach(servoPin);
    servo1.write(90);
    Serial.println("90 is now");
    delay(20000);
}

void loop() {
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Kazdream Technologies");
  display.drawString(0, 10, "Cleverest Technologies");
  display.drawString(0, 20, "Project: Pandorica");
  display.drawString(0, 30, "1st usb");
  display.display();
  servo1.write(50);
  Serial.println("50 is now");
  delay(20000);

  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Kazdream Technologies");
  display.drawString(0, 10, "Cleverest Technologies");
  display.drawString(0, 20, "Project: Pandorica");
  display.drawString(0, 30, "2nd usb");
  display.display();
  servo1.write(135);
  Serial.println("135 is now");
  delay(20000);

  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Kazdream Technologies");
  display.drawString(0, 10, "Cleverest Technologies");
  display.drawString(0, 20, "Project: Pandorica");
  display.drawString(0, 30, "No usb");
  display.display();
  servo1.write(90);
  Serial.println("90 is now");
  delay(30000);
}
