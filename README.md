MIDI_ArpTrigger
===============

Sends +5V (or +3.3V for 3.3V boards) pulses on the configured pin (defaults to pin 13).  
The MIDI standard states that there are 24 clock messages each quarter note. Hence, the software uses a divisor for the triggered signal.  
The default is 24 resulting in quarter note trigger pulses.
A trigger pulse simply raises the output pin for a short time.

To change the divisor there is a simple SysEx protocol which contains only one byte for the divisor surrounded by the `0xF0` as the starting and `0xF7` as the ending marker.