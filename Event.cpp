#include "Event.h"
#include <pthread.h>

Event::Event()
{
  if(pthread_cond_init(&m_Cond,0)!=0)
    throw "pthread_cond_init failed!";
}

Event::~Event()
{
  pthread_cond_destroy(&m_Cond);
}

int Event::Signal()
{
  return pthread_cond_signal(&m_Cond);
}

int Event::Broadcast()
{
  return pthread_cond_broadcast(&m_Cond);
}

int Event::Wait()
{
  return pthread_cond_wait(&m_Cond,m_Mutex);
}
