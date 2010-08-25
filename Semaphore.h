#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include <semaphore.h>
class Semaphore
{
  sem_t m_Sem;
  int m_Max;
public:
  Semaphore(bool pshared=false,int max=1);
  ~Semaphore();
  void Lock();
  void Unlock();
};
#endif
