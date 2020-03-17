#include "Adafruit_Crickit.h"
#include <Adafruit_CircuitPlayground.h>

Adafruit_Crickit crickit;

// I just pulled this setup from the example
void setup() {
  Serial.begin(115200);

  CircuitPlayground.begin();

  if(!crickit.begin()){
    Serial.println("ERROR!");
    while(1);
  } else {
    Serial.println("Crickit started");
  }

  crickit.setPWMFreq(CRICKIT_DRIVE1, 1000);
}

// this is the frequency chosen by the buttons. 1 = 1HZ, 2 = 2HZ, etc
int freq = 0;

// start the elecromagnet OFF
int state = CRICKIT_DUTY_CYCLE_OFF;

// the amount of times the loop executed
int count = 0;

void loop() {
  count++;

  // handle inputs
  if (CircuitPlayground.leftButton() && freq > 0) {
    freq--;
    CircuitPlayground.clearPixels();
    lightup(freq);
    delay(250); // delay prevents going up or down too fast
  }

  if (CircuitPlayground.rightButton() && freq < 16) {
    freq++;
    lightup(freq);
    delay(250);
  }

  // one time per second = 1000 / 1 = 1000
  // twice per second = 1000 / 2 = 500
  if (count < 1000/(freq+1)) {
    // not time to switch states yet, delay and start over
    delay(1);
    return;
  }

  // time to switch electromagnet states
  count = 0;
  if (state == CRICKIT_DUTY_CYCLE_OFF) {
    state = CRICKIT_DUTY_CYCLE_MAX;
  } else {
    state = CRICKIT_DUTY_CYCLE_OFF;
  }

  crickit.analogWrite(CRICKIT_DRIVE1, state);
}

// lights up based on the frequency selected (amount and color change)
void lightup(int freq) {
  for (int i = 0; i < freq; i++) {
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(16 * freq));
  }
}
