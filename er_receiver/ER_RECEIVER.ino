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

  long sectors = 4;
  long M = numLeds * sectors;

  long veleta_lima2 = map(veleta, 0, 360, 0, M);
  int anemometro_lima2 = map(anemometro, 0, 30, 0, 90);

  Serial.print("#");
  Serial.print(ledPins[veleta_lima2 % numLeds]);
  Serial.print("$");
  Serial.print(anemometro);
  Serial.print("%");
  Serial.print(veleta);
  Serial.print("&");
  Serial.println(ledPins[veleta_lima2 % numLeds]);

  delay(1000);
}

void onVeletaLimaChange() {}
void onAnemometroLimaChange() {}