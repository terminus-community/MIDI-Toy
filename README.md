# MIDI-Toy

Hello. This repository contains a little toy.

If you have heard of [Pixelflut](https://github.com/defnull/pixelflut), well, it is very similar,
except we don't use a screen, we have a MIDI synthesizer instead!

I am currently doing the records on [Casio Privia PX-350M](https://www.casio-intl.com/mea/en/emi/products/px350m/) and **E-Mu 0404 USB**.

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

Instrument 1 can be a piano, instrument 128 might sound like shooting.

### MIDI System commands

* [Start](http://192.168.4.1/start)
* [Stop](http://192.168.4.1/stop)
* [Reset](http://192.168.4.1/reset)

There are no options, the response will be equal to `ACK`.

## Links

### MIDI commands descriptions

* [Music software development](http://www.music-software-development.com/midi-tutorial.html)
* [CCRMA](https://ccrma.stanford.edu/~craig/articles/linuxmidi/misc/essenmidi.html)
