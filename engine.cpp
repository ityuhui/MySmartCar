#include "engine.h"
#include "definition.h"
#include <Arduino.h>

Engine * Engine::s_instance = NULL;

Engine::Engine(int dir1_a, int dir2_a, int dir1_b, int dir2_b, int speed_a_port, int speed_b_port, int speed_a_value, int speed_b_value):
m_dir1_a(dir1_a),
m_dir2_a(dir2_a),
m_dir1_b(dir1_b),
m_dir2_b(dir2_b),
m_speed_a_port(speed_a_port),
m_speed_b_port(speed_b_port),
m_speed_a_value(speed_a_value),
m_speed_b_value(speed_b_value)
{
  
}

Engine::~Engine()
{
  
}

void
Engine::setupMe()
{
  pinMode(m_dir1_a, OUTPUT);
  pinMode(m_dir2_a, OUTPUT);
  pinMode(m_dir1_b, OUTPUT);
  pinMode(m_dir2_b, OUTPUT);

  pinMode(m_speed_a_port, OUTPUT);
  pinMode(m_speed_b_port, OUTPUT);
}

Engine *
Engine::instance()
{
  if( NULL == s_instance){
    s_instance = new Engine(ENGINE_IN1,ENGINE_IN2,ENGINE_IN3,ENGINE_IN4,ENGINE_PWM_ENA,ENGINE_PWM_ENB,ENGINE_A_SPEED,ENGINE_B_SPEED);
  }
  return s_instance;
}

void
Engine::setCarSpeed()
{
  analogWrite(m_speed_a_port, m_speed_a_value);
  analogWrite(m_speed_b_port, m_speed_b_value);
}

void
Engine::stopEngine()
{
  digitalWrite(m_dir1_a,HIGH);
  digitalWrite(m_dir2_a,HIGH);
  digitalWrite(m_dir1_b,HIGH);
  digitalWrite(m_dir2_b,HIGH);  
}

void
Engine::forward()
{
  digitalWrite(m_dir1_a,HIGH);
  digitalWrite(m_dir2_a,LOW);
  digitalWrite(m_dir1_b,HIGH);
  digitalWrite(m_dir2_b,LOW);  
}

void
Engine::backward()
{
  digitalWrite(m_dir1_a,LOW);
  digitalWrite(m_dir2_a,HIGH);
  digitalWrite(m_dir1_b,LOW);
  digitalWrite(m_dir2_b,HIGH);  
}

void
Engine::turnLeft()
{
  digitalWrite(m_dir1_a,HIGH);
  digitalWrite(m_dir2_a,LOW);
  digitalWrite(m_dir1_b,LOW);
  digitalWrite(m_dir2_b,HIGH);  
}

void
Engine::turnRight()
{
  digitalWrite(m_dir1_a,LOW);
  digitalWrite(m_dir2_a,HIGH);
  digitalWrite(m_dir1_b,HIGH);
  digitalWrite(m_dir2_b,LOW);  
}

