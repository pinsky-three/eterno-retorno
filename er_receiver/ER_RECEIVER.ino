#include "arduino_secrets.h"
#include "thingProperties.h"

const int ledPins[] = {13, 12, 11, 10, 9,  8,  7,  6,  5,
                       4,  3,  2,  14, 15, 16, 17, 21, 20};

const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(9600);
  delay(1500);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  int veleta_lima2 = map(veleta, 0, 360, 0, 5);
  int anemometro_lima2 = map(anemometro, 0, 7, 0, 90);

  Serial.print("#");
  Serial.print(ledPins[veleta_lima2]);
  Serial.print("$");
  Serial.print(anemometro_lima2);
  Serial.print("%");
  Serial.print(veleta_lima2);
  Serial.print("&");
  Serial.println(ledPins[veleta_lima2]);

  delay(1000);
}

void onVeletaLimaChange() {}
void onAnemometroLimaChange() {}