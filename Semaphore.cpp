#include "Semaphore.h"
#include <stdexcept>
Semaphore::Semaphore(bool pshared,int initial)
  : m_Owner(pthread_self())
{
  m_Sem = new sem_t();
  if(sem_init(m_Sem,(pshared?1:0),initial)==-1)
    throw std::runtime_error("sem_init failed");
}
Semaphore::~Semaphore()
{
  if(pthread_equal(m_Owner,pthread_self())) 
  {
    sem_destroy(m_Sem);
    delete m_Sem;
  }
}
void Semaphore::Lock()
{
  if(sem_wait(m_Sem)!=0)
    throw std::runtime_error("sem_wait failed");
}
void Semaphore::Unlock()
{
  if(sem_post(m_Sem)!=0)
    throw std::runtime_error("sem_post failed");
}
