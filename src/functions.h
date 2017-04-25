#ifndef functions_h
#define functions_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>

void debug(JsonObject& req, JsonObject& res){
  req.printTo(Serial);
};

void setAll(JsonObject& req, JsonObject& res, Adafruit_NeoPixel& pix){
  char* function;
  function = req["function"];
  if(function == 'setAll'){
    uint8_t num_pixels = pix.numPixels();
    for(int i=0; i<num_pixels; i++){
      uint8_t red = req["red"];
      uint8_t green = req["green"];
      uint8_t blue = req["blue"];
      pix.setPixelColor(i, red, green, blue);
    }
    pix.show();
    res["status"] = true;
  }
};

void setPixel(JsonObject& req, JsonObject& res, Adafruit_NeoPixel& pix){
  char* function;
  function = req["function"];
  if(function == "setPixel"){
    uint16_t index = req["index"];
    if(index <= pix.numPixels()){
      uint8_t red = req["red"];
      uint8_t green = req["green"];
      uint8_t blue = req["blue"];
      pix.setPixelColor(index, red, green, blue);
      pix.show();
      res["status"] = true;
    }
    else{
      res["status"] = false;
    }
  }
}

#endif
