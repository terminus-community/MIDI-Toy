/*
 * RtMIDI example that demonstrates a random MIDI output.
 * Creates a virtual MIDI output device and generates random notes.
 * 
 * Requires RtMIDI library, but it's typically available
 * in your package manager.
 * 
 * TODO: maybe I can change a title for the MIDI device?..
 * Now it's something along the lines of "RtMIDI output client: Console".
 *
 * P.S.: use this example however you want,
 * I made it to learn RtMIDI.
 * 
 * 6r1d, 2020.
 */

#include <iostream>
#include <cstdlib>
#include <signal.h>

#include "RtMidi.h"

#include "rand_util.h"
#include "timing.h"

using namespace std;

// Determines if a process should be stopped
bool done;
// Determines if we send "note on"
// or "note off" signal?
bool msg_mode = false;

// Stops the MIDI output
static void finish(int ignore){
  done = true;
}

int main() {
  // Handle SIGINT / ctrl-c interuption
  done = false;
  (void) signal(SIGINT, finish);

  // Start RtMIDI
  RtMidiOut *midiout = new RtMidiOut();
  // Define a variable to store a MIDI message
  std::vector<unsigned char> message;
  // Create a virtual port
  midiout->openVirtualPort("Console");

  // Start counting time
  double ma = millis();

  init_random();
  int rr = rng_random(-10, 10);

  // Send out a series of MIDI messages.
  // Program change: 192, 5
  message.push_back( 192 );
  message.push_back( 5 );
  midiout->sendMessage( &message );
  // Control Change: 176, 7, 100 (volume)
  message[0] = 176;
  message[1] = 7;
  message.push_back( 100 );
  midiout->sendMessage( &message );

  // Feed MIDI signals,
  // await interruption
  while ( !done ) {
      if (millis() - ma > 100.) {
          ma = millis();
          // Print dots for debug
          // printf("."); fflush(stdout);
          // Send notes
          if (msg_mode) {
            // Sending note_on
            // Pick a new note
            rr = rng_random(-5, 5) * 2;
            message[0] = 144;
            message[1] = 64 + rr;
            message[2] = 90;
            midiout->sendMessage( &message );
          }
          else {
            // Sending note_off
            message[0] = 128;
            message[1] = 64 + rr;
            message[2] = 40;
            midiout->sendMessage( &message );
          }
          msg_mode = !msg_mode;
      }
  }

  delete midiout;
  return 0;
}
