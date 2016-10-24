#include "car.h"
#include "definition.h"

Car::Car():leftSensor(NULL),midSensor(NULL),rightSensor(NULL)
{
  newSensors();
}

Car::~Car()
{
  freeSensors();
}



void 
Car::newSensors()
{
  leftSensor  = new IDS(LEFT_IDS_PORT);
  midSensor   = new IDS(MIDDLE_IDS_PORT);
  rightSensor = new IDS(RIGHT_IDS_PORT);  
}

void
Car::freeSensors()
{
  FREEUP(leftSensor);
  FREEUP(midSensor);
  FREEUP(rightSensor);
}

void
Car::setupMe()
{
  setupSensors();
}

void
Car::setupSensors()
{
  leftSensor->setupMe();
  midSensor->setupMe();
  rightSensor->setupMe();
}


void
Car::go()
{
  if(leftSensor->meetObstacle()){
      backward();
      stopEngine();
      turnRight();
  } else if(midSensor->meetObstacle()){
      backward();
      stopEngine();
      turnRight();
  } else if(rightSensor->meetObstacle()){
      backward();
      stopEngine();
      turnLeft();
  } else {
      forward();
  }
}

