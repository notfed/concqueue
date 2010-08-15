#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>
class Mutex
{
  pthread_mutex_t m_Mutex;
public:
  Mutex();
  virtual ~Mutex();
  void Lock();
  void Unlock();
  operator pthread_mutex_t*();
};
#endif
