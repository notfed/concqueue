#ifndef COND_H
#define COND_H
#include <pthread.h>
#include "DateTime.h"
#include "Mutex.h"
class Cond
{
  pthread_cond_t m_Cond;
public:
  Cond();
  virtual ~Cond();
  int Wait(Mutex&);
  int TimedWait(Mutex&,const DateTime&);
  int Broadcast();
  int Signal();
  operator pthread_cond_t*();
};
#endif
