//Albin Mouton 01/11/2021

#include <ArduinoJson.h>
#include <FastLED.h>

//CONFIGURATION IS HERE
#define NUM_LEDS 33 
#define DATA_PIN 3
#define LED_DRIVER WS2812
#define LED_COLOR_OREDER GRB

CRGB leds[NUM_LEDS];



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  FastLED.addLeds<LED_DRIVER,DATA_PIN,LED_COLOR_OREDER>(leds,NUM_LEDS); 
  FastLED.setBrightness(255);
  FastLED.clear();
  FastLED.show();
}

void fadeall(int drop) { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(drop); } }


void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial.available())
    delay(50);

  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, Serial);
  JsonObject root = doc.as<JsonObject>();

  for (JsonPair kv : root) {
    Serial.print(kv.key().c_str());
    Serial.print(" : ");
    Serial.println(kv.value().as<char*>());
    if(strcmp(kv.key().c_str(), "brightness")==0 ){ //Sets Brightness
      FastLED.setBrightness(kv.value().as<int>());
    }
    if(strcmp(kv.key().c_str(), "fadeall")==0 ){ //Fades Every LEDs
      fadeall(kv.value().as<int>());
    }
    if(strcmp(kv.key().c_str(), "clear")==0 ){ //Clears (sets every LEDs to black)
      FastLED.clear();
    }
    if(* kv.key().c_str() == 'R'){ //Sets the RED channel of a single LED
      uint8_t indice = atoi((kv.key().c_str() +1));
      int color = kv.value().as<int>();
      leds[indice].r = color;
    }
    if(* kv.key().c_str() == 'G'){ //Sets the GREEN channel of a single LED
      uint8_t indice = atoi((kv.key().c_str() +1));
      int color = kv.value().as<int>();
      leds[indice].g = color;
    }
    if(* kv.key().c_str() == 'B'){ //Sets the BLUE channel of a single LED
      uint8_t indice = atoi((kv.key().c_str() +1));
      int color = kv.value().as<int>();
      leds[indice].b = color;
    }
  }
  FastLED.show(); 

}
