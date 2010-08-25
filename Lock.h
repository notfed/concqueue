#ifndef LOCK_H
#define LOCK_H
template <class T>
class Lock
{
  T& m_Lock;
public:  
  Lock(T);
  virtual ~Lock();
};

template <class T>
Lock<T>::Lock(T newLock) 
  : m_Lock(newLock)
{ 
  m_Lock.Lock();
}

template <class T>
Lock<T>::~Lock()
{
  m_Lock.Unlock();
}

#endif
