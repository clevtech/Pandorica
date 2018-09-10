#include <Arduino.h>            // Standard Arduino library
#include <Servo.h>              // Library to use servo motors
#include <Wire.h>               // Library to use I2C to display
#include "SSD1306Wire.h"        // Display library
#include <WiFi.h>               // Library to use WiFi


// Constants of WIFI
const char* ssid     = "Pandorica";
const char* password = "12345678";

// Pin of servo and green light
static const int servoPin = 12;
int GRN = 16;

// Initialize display
SSD1306Wire  display(0x3c, 5, 4);

// Initialize web server on 80th port
WiFiServer server(80);

// Initialize servo motor
Servo servo1;

// Function to change IP to string variable
String IpAddress2String(const IPAddress& ipAddress)
{
  return String(ipAddress[0]) + String(".") +\
  String(ipAddress[1]) + String(".") +\
  String(ipAddress[2]) + String(".") +\
  String(ipAddress[3])  ;
}

// Setup
void setup() {
  // Begin serial connection
    Serial.begin(115200);

    // Define pin mode to output
    pinMode(GRN, OUTPUT);
    delay(20000);

    // Initialize display
    display.init();
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Kazdream Technologies");
    display.drawString(0, 10, "Cleverest Technologies");
    display.drawString(0, 20, "Project: Pandorica");

    // Create access point
    WiFi.softAP(ssid, password);
    // Begin server
    server.begin();
    String IP2 = IpAddress2String(WiFi.softAPIP());
    Serial.print("My IP is: ");
    Serial.println(IP2);
    Serial.println(WiFi.softAPIP());
    display.drawString(0, 30, IP2);
    display.display();
    servo1.attach(servoPin);
    servo1.write(90);
    Serial.println("90 is now");
}

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/0\">here</a> to disconnect USB.<br>");
            client.print("Click <a href=\"/1\">here</a> to connect 1st USB.<br>");
            client.print("Click <a href=\"/2\">here</a> to connect 2nd USB.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /2")) {
          digitalWrite(GRN, HIGH);
          display.clear();
          display.setFont(ArialMT_Plain_10);
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 0, "Kazdream Technologies");
          display.drawString(0, 10, "Cleverest Technologies");
          display.drawString(0, 20, "Project: Pandorica");
          display.drawString(0, 30, "2nd usb");
          display.display();
          servo1.write(125);
          Serial.println("135 is now");
        }
        if (currentLine.endsWith("GET /1")) {
          digitalWrite(GRN, HIGH);
          display.clear();
          display.setFont(ArialMT_Plain_10);
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 0, "Kazdream Technologies");
          display.drawString(0, 10, "Cleverest Technologies");
          display.drawString(0, 20, "Project: Pandorica");
          display.drawString(0, 30, "1st usb");
          display.display();
          servo1.write(60);
          Serial.println("50 is now");
        }
        if (currentLine.endsWith("GET /0")) {
          digitalWrite(GRN, LOW);
          display.clear();
          display.setFont(ArialMT_Plain_10);
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 0, "Kazdream Technologies");
          display.drawString(0, 10, "Cleverest Technologies");
          display.drawString(0, 20, "Project: Pandorica");
          display.drawString(0, 30, "no usb");
          display.display();
          servo1.write(90);
          Serial.println("90 is now");
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
}
}
