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
      String function;
      function = req["function"].asString();
      if(function == "setAll"){
        setAll(pixels, req, res);
      }
      else if(function == "setPixel"){
        setPixel(pixels, req, res);
      }
      else {
        ;
      }
    }
  }
}
