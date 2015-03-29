#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

static const int OUTPUT_PIN = 13;

byte divisor = 24;
byte counter = 0;

void handleStart() {
  counter = 1;
  sendPulse();
}

void handleStop() {
  counter = 0;
}

void handleClock() {
  if (counter == divisor) {
    counter = 1;
    sendPulse();
  }
  else {
    counter++;
  }
}

void handleSysEx(byte *array, unsigned size) {
  divisor = array[1];
}

inline void sendPulse() {
  digitalWrite(OUTPUT_PIN, HIGH);
  delay(50);
  digitalWrite(OUTPUT_PIN, LOW);
}

// -----------------------------------------------------------------------------

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  MIDI.setHandleStart(handleStart);
  MIDI.setHandleStop(handleStop);
  MIDI.setHandleClock(handleClock);

  MIDI.setHandleSystemExclusive(handleSysEx);

  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  MIDI.read();
}
