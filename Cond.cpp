#include "Cond.h"
#include "Time.h"

Cond::Cond()
{
  pthread_cond_init(&m_Cond,0);
}

Cond::~Cond()
{
  pthread_cond_destroy(&m_Cond);
}

int Cond::TimedWait(Time& time, Mutex&, mutex, Time& time)
{
  return pthread_timedwait(*this,mutex,time);
}

int Cond::Wait(Mutex& mutex)
{
  return pthread_cond_wait(m_Cond,mutex);
}

Cond::operator pthread_cond_t*()
{
  return &m_Cond;
}
