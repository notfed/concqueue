#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include <semaphore.h>
#include <pthread.h>
class Semaphore
{
  const pthread_t m_Owner;
  sem_t *m_Sem;
public:
  Semaphore(bool pshared=false,int initial=1);
  ~Semaphore();
  void lock();
  void unlock();
};
#endif
