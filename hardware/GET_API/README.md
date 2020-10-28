# Note output code for ESP32 Wroom.

I am using my own [MIDI I/O](https://github.com/6r1d/enhancing_boards/tree/master/MIDI_IO) board
from my "enhancing boards" repo.

To exchange notes with a synthesizer, I am using `Serial2` port.

* ESP32's `IO16` pin or UART `RX2` receives notes from the MIDI IO board.
* ESP32's `IO17` pin or UART `TX2` sends notes to the MIDI IO board.

## Links

### ESP32-related sources

* [ESP32 Arduino serial source](https://github.com/espressif/arduino-esp32/blob/8fcc91485364b334c51447686bc168e9160d093f/cores/esp32/HardwareSerial.cpp)
* [Arduino MIDI commands](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Midi)
* [ESP32 Arduino HTTP server tutorial](https://techtutorialsx.com/2017/12/17/esp32-arduino-http-server-getting-query-parameters/)
