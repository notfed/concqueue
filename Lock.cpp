#include "Lock.h"
Lock::Lock(Mutex& newMutex) 
  : m_Mutex(&newMutex)
{ 
  m_Mutex->Lock();
}
Lock::~Lock()
{
  m_Mutex->Unlock();
}
