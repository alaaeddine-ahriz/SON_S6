#include <Audio.h>
#include "new_pitchshifter.h" // Make sure this matches the class name generated by Faust

AudioInputI2S in;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;

// Assuming "new_pitchshifter" is the class name generated by Faust
new_pitchshifter new_pitchshifter;

// Modify these connections to route through the new_pitchshifter
AudioConnection* patchCords[3];

void setup() {
  Serial.begin(9600);
  AudioMemory(6);
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(10); // in dB
  audioShield.volume(0.8);

  // Initialize new_pitchshifter if necessary
  // mynew_pitchshifter.init();

  // Setup audio connections
  patchCords[0] = new AudioConnection(in, 0, new_pitchshifter, 0);
  patchCords[1] = new AudioConnection(new_pitchshifter, 0, out, 0);
  patchCords[2] = new AudioConnection(new_pitchshifter, 0, out, 1);
}

void loop() {
  int sensorValue0 = analogRead(A0);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);

  float volume = sensorValue3 / 1023.0;
  audioShield.volume(volume);
  
  float shift = map(sensorValue0, 0, 1023, -10, 10);
  new_pitchshifter.setParamValue("shift", shift);
  float room_size = map(sensorValue2, 0, 1023, 0, 1);
  new_pitchshifter.setParamValue("room_size", room_size);

  Serial.print("********************************************");
  Serial.print("Shift : ");
  Serial.println(shift);

  delay(10);
}
