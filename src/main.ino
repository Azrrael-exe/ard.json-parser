#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>

#include "functions.h"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, 4, NEO_GRB + NEO_KHZ800);

void setup(){
  pixels.begin();
  Serial.begin(115200);
}

void loop(){
  if(Serial.available() > 0){
    StaticJsonBuffer<200> jsonBuffer;
    String inp = Serial.readStringUntil('\n');
    JsonObject& req = jsonBuffer.parseObject(inp);
    JsonObject& res = jsonBuffer.createObject();
    if(req.success()){
      debug(req, res);
      setAll(req, res, pixels);
      setPixel(req, res, pixels);
      res.printTo(Serial);
    }
  }
}
