#include "Mutex.h"

Mutex::Mutex()
{
  pthread_mutex_init(&m_Mutex,0);
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&m_Mutex);
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
