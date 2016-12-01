#include "car.h"
#include "definition.h"
#include "ids.h"
#include "engine.h"
#include <Arduino.h>

Car::Car():
leftSensor(NULL),
midSensor(NULL),
rightSensor(NULL),
engine(NULL)
{
  newSensors();
  newEngine();
}

Car::~Car()
{
  freeSensors();
  freeEngine();
}

void
Car::setupMe()
{
  setupSensors();
  setupEngine();
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
Car::setupSensors()
{
  leftSensor->setupMe();
  midSensor->setupMe();
  rightSensor->setupMe();
}

void
Car::newEngine()
{
  engine = Engine::instance();
}

void
Car::setupEngine()
{
  engine->setupMe();
}

void
Car::freeEngine()
{
// engine is singleton, so it does not need to free
}

void
Car::beforeGo()
{
  engine->stopEngine();
  engine->setCarSpeed(); 
}

void
Car::go()
{
  if(leftSensor->meetObstacle()){
      engine->backward();
      engine->stopEngine();
      engine->turnRight();
  } else if(midSensor->meetObstacle()){
      engine->backward();
      engine->stopEngine();
      engine->turnRight();
  } else if(rightSensor->meetObstacle()){
      engine->backward();
      engine->stopEngine();
      engine->turnLeft();
  } else {
      engine->forward();
  }
}

void
Car::testEngine()
{
  engine->backward();
    delay(1000);
  engine->stopEngine();
    delay(1000);
  engine->turnRight();
    delay(1000);
   engine->stopEngine();
    delay(1000);
   engine->turnLeft();
    delay(1000);
    engine->stopEngine();
    delay(1000);
    engine->forward();
    delay(1000);
}

