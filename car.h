#ifndef _CAR_H
#define _CAR_H

#include "ids.h"

class IDS;
class Engine;

class Car 
{
public:
  Car();
  ~Car();
  void setupMe();
  void beforeGo();
  void go();
  void testEngine();

private:
  void newSensors();
  void freeSensors();
  void setupSensors();

  void newEngine();
  void freeEngine();
  void setupEngine();

  void forward();
  void backward();
  void turnLeft();
  void turnRight();
  void stopEngine();
  
  IDS *leftSensor;
  IDS *midSensor;
  IDS *rightSensor;

  Engine *engine;
};

#endif
