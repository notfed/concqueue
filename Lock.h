#ifndef LOCK_H
#define LOCK_H
#include "Mutex.h"
#include <pthread.h>
class Lock
{
  Mutex* const m_Mutex;
public:  
  Lock(Mutex&);
  virtual ~Lock();
};
#endif
