#include "Lock.h"
#include <pthread.h>
using namespace std;
Lock::Lock(pthread_mutex_t& newMutex) 
  : m_Mutex(newMutex)
{ 
  pthread_mutex_lock(&m_Mutex);
}
Lock::~Lock()
{
  pthread_mutex_unlock(&m_Mutex);
}
