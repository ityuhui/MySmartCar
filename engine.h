#ifndef _ENGINE_H
#define _ENGINE_H

class Engine {
public:
  static Engine * instance();
  ~Engine();
  
  void setupMe();
  void setCarSpeed();
  void stopEngine();
  void forward();
  void backward();
  void turnLeft();
  void turnRight();
private:
  Engine(int,int,int,int,int,int,int,int);
  static Engine *s_instance;
  int m_dir1_a;
  int m_dir2_a;
  int m_dir1_b;
  int m_dir2_b;

  int m_speed_a_port;
  int m_speed_a_value;
  int m_speed_b_port;
  int m_speed_b_value;
    
};

#endif
