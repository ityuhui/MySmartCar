#ifndef _CAR_H
#define _CAR_H

#include "ids.h"

class IDS;

class Car 
{
public:
  Car();
  ~Car();
  void setupMe();
  void go();

private:
  void newSensors();
  void freeSensors();
  void setupSensors();

  void forward();
  void backward();
  void turnLeft();
  void turnRight();
  void stopEngine();
  
  IDS *leftSensor;
  IDS *midSensor;
  IDS *rightSensor;
};

#endif
