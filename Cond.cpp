#include "Cond.h"
#include "Mutex.h"
#include "DateTime.h"

int Cond::TimedWait(Mutex& mutex, const DateTime& tim)
{
  struct timespec tmpTime(tim);
  return pthread_cond_timedwait(&m_Cond,mutex,&tmpTime);
}

int Cond::Wait(Mutex& mutex)
{
  return pthread_cond_wait(&m_Cond,mutex);
}
