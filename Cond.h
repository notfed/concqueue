#ifndef COND_H
#define COND_H
#include <pthread.h>
#include "Time.h"
class Cond
{
  pthread_cond_t m_Cond;
public:
  inline Cond() { pthread_cond_init(&m_Cond,0); }
  inline virtual ~Cond() { pthread_cond_destroy(&m_Cond); }
  int Wait(Mutex&);
  int TimedWait(Mutex&,const TimeSpec&);
  int Broadcast();
  int Signal();
  operator pthread_cond_t*() { return &m_Cond; }
};
#endif
