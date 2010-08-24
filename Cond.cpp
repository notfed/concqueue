#include "Cond.h"
#include "Mutex.h"
#include "DateTime.h"
#include <stdexcept>
#include <iostream>


Cond::Cond()
{
  if(pthread_cond_init(&m_Cond,0)!=0)
    throw std::runtime_error("pthread_cond_init failed"); 
}
Cond::~Cond()
{
  if(pthread_cond_destroy(&m_Cond)!=0)
    std::cerr << "pthread_cond_destroy failed" << std::endl; 
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
