#include "Mutex.h"
#include <stdexcept>
#include <iostream>
#include <pthread.h>

Mutex::Mutex()
  : m_Owner(pthread_self())
{
  m_Mutex = new pthread_mutex_t();
  if(pthread_mutex_init(m_Mutex,0)!=0)
    throw std::runtime_error("pthread_mutex_init failed");
}

Mutex::~Mutex()
{
  if(pthread_equal(m_Owner,pthread_self()))
  {
    if(pthread_mutex_destroy(m_Mutex)!=0)
      std::cerr << "pthread_mutex_destroy failed" << std::endl;
    delete m_Mutex;
  }
}

void Mutex::Lock()
{
  if(pthread_mutex_lock(m_Mutex)!=0)
    throw std::runtime_error("pthread_mutex_lock failed");
}

void Mutex::Unlock()
{
  if(pthread_mutex_unlock(m_Mutex)!=0)
    throw std::runtime_error("pthread_mutex_unlock failed");
}

Mutex::operator pthread_mutex_t* const()
{
  return m_Mutex;
}
