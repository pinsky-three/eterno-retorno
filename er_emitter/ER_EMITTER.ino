#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500);

  Serial.println("System Ready");
  
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
 
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  veleta = analogRead(32);
  anemometro = analogRead(33);
  
  veleta = map(veleta, 0, 4095, 0, 360);
  anemometro = map(anemometro, 0, 4095, 0, 30);
  
  Serial.print(analogRead(32));
  Serial.print(";");
  Serial.print(veleta);
  Serial.print("///");
  Serial.print(analogRead(33));
  Serial.print(";");
  Serial.println(anemometro);
  
  delay(1000);
}




