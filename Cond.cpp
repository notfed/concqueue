#include "Cond.h"
#include "Mutex.h"
#include "DateTime.h"
#include <stdexcept>
#include <iostream>
#include <pthread.h>
#include <valgrind/helgrind.h>


Cond::Cond()
  : m_Owner(pthread_self())
{
  m_Cond = new pthread_cond_t();
  if(pthread_cond_init(m_Cond,0)!=0)
    throw std::runtime_error("pthread_cond_init failed"); 
  ANNOTATE_HAPPENS_BEFORE(this);
}
Cond::~Cond()
{
  ANNOTATE_HAPPENS_AFTER(this);
  if(pthread_equal(m_Owner,pthread_self()))
  {
    if(pthread_cond_destroy(m_Cond)!=0)
      std::cerr << "pthread_cond_destroy failed" << std::endl; 
    delete m_Cond;
  }
}
Cond::operator pthread_cond_t* const() 
{ 
  ANNOTATE_HAPPENS_AFTER(this);
  return m_Cond; 
}

int Cond::TimedWait(Mutex& mutex, const DateTime& tim)
{
  ANNOTATE_HAPPENS_AFTER(this);
  struct timespec tmpTime(tim);
  return pthread_cond_timedwait(m_Cond,mutex,&tmpTime);
}

int Cond::Wait(Mutex& mutex)
{
  ANNOTATE_HAPPENS_AFTER(this);
  return pthread_cond_wait(m_Cond,mutex);
}

int Cond::Signal()
{
  ANNOTATE_HAPPENS_AFTER(this);
  return pthread_cond_signal(m_Cond);
}
int Cond::Broadcast()
{
  ANNOTATE_HAPPENS_AFTER(this);
  return pthread_cond_broadcast(m_Cond);
}
