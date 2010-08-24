#include "Mutex.h"
#include <stdexcept>
#include <iostream>

Mutex::Mutex()
{
  if(pthread_mutex_init(&m_Mutex,0)!=0)
    throw std::runtime_error("pthread_mutex_init failed");
}

Mutex::~Mutex()
{
  if(pthread_mutex_destroy(&m_Mutex)!=0)
    std::cerr << "pthread_mutex_destroy failed" << std::endl;
}

void Mutex::Lock()
{
  pthread_mutex_lock(&m_Mutex);
}

void Mutex::Unlock()
{
  pthread_mutex_unlock(&m_Mutex);
}

Mutex::operator pthread_mutex_t*()
{
  return &m_Mutex;
}
