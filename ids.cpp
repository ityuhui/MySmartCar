#include "ids.h"
#include <Arduino.h>

IDS::IDS(int port):m_port(port)
{
  
}

void
IDS::setupMe()
{
  pinMode(m_port, INPUT);
}

bool
IDS::meetObstacle()
{
  bool res = false;
  if( LOW == digitalRead(m_port) ){
    res = true;
  }
  return res;
}


