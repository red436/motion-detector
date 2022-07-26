
#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>
WiFiMulti wifiMulti;
HTTPClient http;
// constants won't change. They're used here to set pin numbers:
const int PIRPin = 2;     // the number of the PIR motion sensor
const int ledPin = 13;

// variables will change:
int PIRState = 0;         // variable for reading the PIR motion status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(PIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  wifiMulti.addAP("AP_SSID", "AP_PASS");
}

void loop() {
  // read the state of the pushbutton value:
  PIRState = digitalRead(PIRPin);
  http.begin("https://api.pushbullet.com/v2/pushes");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Access-Token", "");

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    int httpCode = http.POST("{\"email\":\"redbeard.436@gmail.com\",\"active\":\"true\",\"type\":\"note\",\"title\":\"Intruder Alert!\",\"body\":\"Someone has trigger the motion sensor!\"}");
  } else {
    delay(100);
  }
}
