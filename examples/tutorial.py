#!/usr/bin/env python3

"""
A very simple example for interacting with MIDI toy using Python 3.
"""

from time import sleep
from urllib.request import urlopen

def main():
    """
    Sends all the notes in available range
    to a synthesizer
    """
    urlopen('http://192.168.4.1/ins?patch=1')
    for midi_note in range(22, 107):
        urlopen(f'http://192.168.4.1/on?pitch={midi_note}&velocity=30')
        sleep(0.1)
        urlopen(f'http://192.168.4.1/off?pitch={midi_note}&velocity=30')
        sleep(0.1)

if __name__ == '__main__':
    main()
