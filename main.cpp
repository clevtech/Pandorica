/*
15 - 0
16 - 110
14 - 88
*/
#include <Arduino.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

int pos = 0;

void Go2A(){
  myservo3.write(20);
  delay(1000);
  // myservo2.write(50);
  // delay(1000);
  //myservo2.write(90);
  delay(1000);

  myservo1.write(85);
  delay(1000);

  myservo3.write(60);
  delay(1000);
  myservo2.write(80);
  delay(1000);
}

void Go2B(){
  myservo3.write(20);
  delay(1000);
  // myservo2.write(50);
  // delay(1000);
  //myservo2.write(90);
  delay(1000);

  myservo1.write(110);
  delay(1000);

  myservo3.write(60);
  delay(1000);
  myservo2.write(80);
  delay(1000);
}

void Go2C(){
  //myservo3.write(30);
  delay(1000);
  // myservo2.write(50);
  // delay(1000);
  //myservo2.write(70);
  //myservo2.write(60);
  delay(1000);
  myservo1.write(50);
  delay(1000);
  //myservo2.write(90);
  delay(1000);
}

void Go2D(){
  //myservo3.write(30);
  delay(1000);
  // myservo2.write(50);
  // delay(1000);
  //myservo2.write(70);
  //myservo2.write(60);
  delay(1000);
  myservo1.write(180);
  delay(1000);
  //myservo2.write(90);
  delay(1000);
}
void setup()
{
  Serial.begin(115200);
  myservo1.attach(14);
  myservo2.attach(17);
  myservo3.attach(19);

  //Go2C();
  Go2B();
  Go2C();
  //Go2A();
  //Go2C();
  //Go2B();
}

void loop(){}
