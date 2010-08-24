#include "Cond.h"
#include "Mutex.h"
#include "DateTime.h"


Cond::Cond()
{
  if(pthread_cond_init(&m_Cond,0)!=0)
    throw "Couldn't initialize Cond"; 
}
Cond::~Cond()
{
  if(pthread_cond_destroy(&m_Cond)!=0)
    throw "Couldn't destroy Cond"; 
}
Cond::operator pthread_cond_t*() 
{ 
  return &m_Cond; 
}

int Cond::TimedWait(Mutex& mutex, const DateTime& tim)
{
  struct timespec tmpTime(tim);
  return pthread_cond_timedwait(&m_Cond,mutex,&tmpTime);
}

int Cond::Wait(Mutex& mutex)
{
  return pthread_cond_wait(&m_Cond,mutex);
}
