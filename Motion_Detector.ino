
#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>
WiFiMulti wifiMulti;
HTTPClient http;
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton
const int ledPin = 13;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  wifiMulti.addAP("Cabezud", "7tWRLmeYWJA");
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  http.begin("https://api.pushbullet.com/v2/pushes");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Access-Token", "o.vLD8TMCvkLFg7M4qxWRhqzSZA8XpNssg");

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    int httpCode = http.POST("{\"email\":\"redbeard.436@gmail.com\",\"active\":\"true\",\"type\":\"note\",\"title\":\"Intruder Alert!\",\"body\":\"Someone has trigger the motion sensor!\"}");
  } else {
    delay(100);
  }
}
