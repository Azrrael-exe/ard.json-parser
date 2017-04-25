#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>
#include "functions.h"

#define interruptPin 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, 4, NEO_GRB + NEO_KHZ800);

void setup(){
  pixels.begin();
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), sensorRead, CHANGE);
}

void loop(){
  if(Serial.available() > 0){
    StaticJsonBuffer<200> jsonBuffer;
    String inp = Serial.readStringUntil('\n');
    JsonObject& req = jsonBuffer.parseObject(inp);
    JsonObject& res = jsonBuffer.createObject();
    if(req.success()){
      setAll(req, res, pixels);
      setPixel(req, res, pixels);
      res.printTo(Serial);
    }
  }
}

void alarmRead(){
  // StaticJsonBuffer<200> jsonBuffer;
  // JsonObject& res = jsonBuffer.createObject();
  // String function;
  // function = 'alarmRead'
  // res["function"] = function;
  // res["alarm"] = digitalRead(interruptPin);
  // res["status"] = true;
  // res.printTo(Serial);
}
