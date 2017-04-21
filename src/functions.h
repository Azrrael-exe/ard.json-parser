#ifndef functions_h
#define functions_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>

void setAll(Adafruit_NeoPixel& pix, JsonObject& req, JsonObject& res){
  uint8_t num_pixels = pix.numPixels();
  for(int i=0; i<num_pixels; i++){
    uint8_t red = req["red"];
    uint8_t green = req["green"];
    uint8_t blue = req["blue"];
    pix.setPixelColor(i, red, green, blue);
  }
  pix.show();
  res["status"] = true;
};

void setPixel(Adafruit_NeoPixel& pix, JsonObject& req, JsonObject& res){
  uint16_t index = req["index"];
  uint8_t red = req["red"];
  uint8_t green = req["green"];
  uint8_t blue = req["blue"];
  pix.setPixelColor(index, red, green, blue);
  pix.show();
  res["status"] = true;
};

#endif
