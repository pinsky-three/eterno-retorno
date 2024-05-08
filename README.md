# The Eternal Return

## Source Code
    
This repository saves the source code of the "The Eternal Return" piece. The code is divided in three major
parts: the emitter_device (er_emitter), the receiver_device (er_receiver) and the io_device (er_io_mega).

### Getting Started

The code is written in C++ and uses the Arduino framework. To compile the code, you need to have the Arduino IDE.
To build and upload the er_emitter and er_receiver, you need to create an `arduino_secrets.h` file in the same folder of each project and fill it with the following content:

```c++
#define SECRET_SSID "<your_ssid>"
#define SECRET_OPTIONAL_PASS "<your_password>"
#define SECRET_DEVICE_KEY "<your_device_key>"
```