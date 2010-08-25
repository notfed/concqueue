#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>
class Mutex
{
  pthread_mutex_t* m_Mutex;
  const pthread_t m_Owner;
public:
  Mutex();
  virtual ~Mutex();
  void Lock();
  void Unlock();
  operator pthread_mutex_t*();
};
#endif
