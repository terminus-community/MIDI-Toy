# MIDI-Toy
Hello. This repository contains a little toy.
If you have heard of Pixelflut, well, it is very similar, except we don't use a screen, we use a MIDI synthesizer.

## HTTP API commands

MIDI command receiver is working in WiFi access point mode. It has a static IP: `192.168.4.1`.

### Press and release key

* To press: `http://192.168.4.1/on?pitch=60&velocity=60`
* To release a key: `http://192.168.4.1/off?pitch=60&velocity=60`

Pitch range is from `22` to `106`.
Velocity range is from `0` to `127`.

When the input is correct, the response will be equal to `ACK`.

### Change an instrument

`http://192.168.4.1/ins?patch=3`

When the input is correct, the response will be equal to `ACK`.

### MIDI System commands

* [Start](http://192.168.4.1/start)
* [Stop](http://192.168.4.1/stop)
* [Reset](http://192.168.4.1/reset)

There are no options, the response will be equal to `ACK`.

## Links

### MIDI commands descriptions

* [Music software development](http://www.music-software-development.com/midi-tutorial.html)
* [CCRMA](https://ccrma.stanford.edu/~craig/articles/linuxmidi/misc/essenmidi.html)
