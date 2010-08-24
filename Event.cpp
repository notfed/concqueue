#include "Event.h"

Event::Event()
{
  if(pthread_cond_init(m_Cond,0)!=0)
    throw "pthread_cond_init failed!";
}

Event::~Event()
{
  if(pthread_cond_destroy(m_Cond)!=0)
    throw "pthread_cond_destroy failed!";
}

int Event::Signal()
{
  return pthread_cond_signal(m_Cond);
}

int Event::Broadcast()
{
  return pthread_cond_broadcast(m_Cond);
}

int Event::Wait()
{
  return pthread_cond_wait(m_Cond,m_Mutex);
}

int Event::Wait(DateTime deadline)
{
  struct timespec t = deadline;
  return pthread_cond_timedwait(m_Cond,m_Mutex,&t);
}
