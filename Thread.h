#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
class Thread
{
  pthread_t m_Thread;
  void Exit(void*);
public:
  typedef void *(*start_routine_t)(void*);
  Thread(start_routine_t,void*);
  virtual ~Thread() { }
  int Cancel();
  int Kill(int);
  int Join(void**);
};
#endif
