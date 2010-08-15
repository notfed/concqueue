#ifndef LOCK_H
#define LOCK_H
#include <pthread.h>
class Lock
{
  pthread_mutex_t& m_Mutex;
public:  
  Lock(pthread_mutex_t&);
  ~Lock();
};
#endif
