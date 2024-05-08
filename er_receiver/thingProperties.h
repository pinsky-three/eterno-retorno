// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "59788853-de11-4deb-8eea-6e0f4b23b898";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onAnemometroLimaChange();
void onVeletaLimaChange();

int anemometro;
int veleta;

void initProperties(){
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

  ArduinoCloud.addProperty(anemometro, READWRITE, ON_CHANGE, onAnemometroLimaChange);
  ArduinoCloud.addProperty(veleta, READWRITE, ON_CHANGE, onVeletaLimaChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);