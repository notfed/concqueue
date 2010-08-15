#include "Thread.h"
#include <exception>
#include <signal.h>
#include <pthread.h>
using namespace std;

Thread::Thread(start_routine_t start_routine, void* start_routine_arg)
{
  if(pthread_create(&m_Thread, 0, start_routine, start_routine_arg)!=0) 
    throw "pthread_create failed";
}
int Thread::Cancel()
{
  return pthread_cancel(m_Thread);
}
int Thread::Kill(int sig)
{
  return pthread_kill(m_Thread,sig);
}
int Thread::Join(void** value_ptr)
{
  return pthread_join(m_Thread,value_ptr);
}
