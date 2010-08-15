#include "Lock.h"
#include <pthread.h>
using namespace std;
Lock::Lock(Mutex& newMutex) 
  : m_Mutex(&newMutex)
{ 
  m_Mutex->Lock();
}
Lock::~Lock()
{
  m_Mutex->Unlock();
}
