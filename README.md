
# Hall Effect Sensor Reading
  
Small implementation of reading two hall effect sensors, more exactly two flow sensors. The sensors are read in thgorugh GPIO interruptions caused by digital level change, so when the hall effect happens in this case means 1ml of fluid lowed throught the sensor.

This project is a proof of concept of a bigger project that I've don't yet wether it will be closed or open source. It uses an ESP32, a MCU by Espressif, that has two cores and a builtin WiFi network interface.

## Installation

 1. Install [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/installation.html#install-shell-commands)
 2. Run with ``platformio run``


 ## Assembled Project

 ![Assembled Project image](/docs/assembled.jpeg)

### Changelog

You can check this project changelog [here](CHANGELOG.md)
