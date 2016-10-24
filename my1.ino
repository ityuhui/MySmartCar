#include "car.h"

Car car;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  car.setupMe();
}

// the loop function runs over and over again forever
void loop() {

  car.go();

  delay(1000);
}
