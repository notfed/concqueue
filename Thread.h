#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
class Thread
{
  pthread_t m_Thread;
  void Exit(void*);
public:
  typedef void *(*Start_routine_f)(void*);
  typedef void *Start_routine_arg_t;
  Thread(Start_routine_f,Start_routine_arg_t);
  virtual ~Thread() { }
  int Cancel();
  int Kill(int);
  int Join(void**);
};
#endif
