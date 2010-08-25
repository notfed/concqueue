#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include <semaphore.h>
#include <pthread.h>
class Semaphore
{
  sem_t *m_Sem;
  const pthread_t m_Owner;
public:
  Semaphore(bool pshared=false,int initial=1);
  ~Semaphore();
  void Lock();
  void Unlock();
};
#endif
