#ifndef EVENT_H 
#define EVENT_H
#include "Mutex.h"
#include "Cond.h"
#include <pthread.h>
class Event
{
  Cond m_Cond;
  Mutex m_Mutex;
public:
  Event();
  virtual ~Event();
  int Signal();
  int Broadcast();
  int Wait();
};
#endif