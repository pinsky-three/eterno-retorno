#include "arduino_secrets.h"
#include "thingProperties.h"

const int bufferSize = 100;
int veletaBuffer[bufferSize];
int anemometroBuffer[bufferSize];
int bufferIndex = 0;
bool isStalled = false;
unsigned long lastChangeTime = 0;
const unsigned long stallThreshold = 5000;  // 5 segundos

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

  int currentVeleta = analogRead(32);
  int currentAnemometro = analogRead(33);

  // Check if the sensors are stalled
  if (currentVeleta ==
          veletaBuffer[(bufferIndex - 1 + bufferSize) % bufferSize] &&
      currentAnemometro ==
          anemometroBuffer[(bufferIndex - 1 + bufferSize) % bufferSize]) {
    if (!isStalled) {
      isStalled = true;
      lastChangeTime = millis();
    } else if (millis() - lastChangeTime > stallThreshold) {
      // If stalled for more than threshold, use the buffer values
      veleta = veletaBuffer[(bufferIndex - 1 + bufferSize) % bufferSize];
      anemometro =
          anemometroBuffer[(bufferIndex - 1 + bufferSize) % bufferSize];
    }
  } else {
    isStalled = false;
    veleta = currentVeleta;
    anemometro = currentAnemometro;
  }

  // Update the buffer
  veletaBuffer[bufferIndex] = veleta;
  anemometroBuffer[bufferIndex] = anemometro;
  bufferIndex = (bufferIndex + 1) % bufferSize;

  // Map the readings to desired range
  veleta = map(veleta, 0, 4095, 0, 360);
  anemometro = map(anemometro, 0, 4095, 0, 30);

  // Print the readings
  Serial.print(currentVeleta);
  Serial.print(";");
  Serial.print(veleta);
  Serial.print("///");
  Serial.print(currentAnemometro);
  Serial.print(";");
  Serial.println(anemometro);

  delay(1000);
}