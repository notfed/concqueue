#include "Semaphore.h"
#include <stdexcept>
#include <iostream>
Semaphore::Semaphore(bool pshared,int max)
{
  if(sem_init(&m_Sem,(pshared?1:0),max)==-1)
    throw std::runtime_error("sem_init failed");
}
Semaphore::~Semaphore()
{
  if(sem_destroy(&m_Sem)!=0)
    std::cerr << "sem_destroy failed" << endl;
}
void Semaphore::Lock()
{
  if(sem_wait(&m_Sem)!=0)
    throw std::runtime_error("sem_wait failed");
}
void Semaphore::Unlock()
{
  if(sem_post(&m_Sem)!=0)
    throw std::runtime_error("sem_post failed");
}
