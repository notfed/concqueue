#include "Thread.h"
#include "Attr.h"
#include <exception>
#include <signal.h>
using namespace std;

Thread::Thread(Start_routine_f start_routine, Start_routine_arg_t arg)
{
  Attr at(PTHREAD_CREATE_JOINABLE);
  if(pthread_create(&m_Thread, at, start_routine, arg)!=0) 
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
  return pthread_join(m_Thread, value_ptr);
}
