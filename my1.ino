#include "car.h"

Car car;


// the setup function runs once when you press reset or power the board
void setup() {
  car.setupMe();
  car.beforeGo();
  //Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //car.go();
  delay(1000);
  car.testEngine();
  //Serial.println("Hello,World");
}
