#include "arduino_secrets.h"
#include "thingProperties.h"

const int ledPins[] = {2,3,4,5,6,7,14,15,16,17,18,19};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  int veleta_lima2 = map(veleta, 0, 360, 0, 5); // random(5);
  int anemometro_lima2 = map(anemometro, 0, 7, 0, 90); // random(90);

  
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


/*
  Since VeletaLima is READ_WRITE variable, onVeletaLimaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onVeletaLimaChange()  {
  // Add your code here to act upon VeletaLima change
}
/*
  Since AnemometroLima is READ_WRITE variable, onAnemometroLimaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAnemometroLimaChange()  {
  // Add your code here to act upon AnemometroLima change
}