#ifndef _IDS_H
#define _IDS_H

class IDS
{
public:
  IDS(int port);
  ~IDS();
  bool meetObstacle();
  void setupMe();
private:
  int m_port;
};

#endif
