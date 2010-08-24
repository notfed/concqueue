#ifndef THREADQUEUE_H
#define THREADQUEUE_H
#include "Mutex.h"
#include "Thread.h"
#include "Event.h"
#include "DateTime.h"
#include "Lock.h"
#include "CallMemFun.h"
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

template <class E>
class ThreadQueue
{
  volatile bool m_Finished;
  Thread m_Thread;
  std::priority_queue<E*,std::vector<E*>,typename E::PtrCompareType> m_Queue;
  Mutex m_QueueLock;
  Event m_QueueEvent;
  E* Dequeue();
  E* TryDequeue(TimeSpan*);
  void* ThreadQueueLoop();
public:
  ThreadQueue();
  virtual ~ThreadQueue();
  void Enqueue(E*); // Add a person to the queue
  void Finish(); // Signal that no more people will be Enqueued
  void Wait(); // Wait for room to finish handling all people currently queued
};

template <class E>
ThreadQueue<E>::ThreadQueue()
  : m_Finished(false),
    m_Thread(&CallMemFun<ThreadQueue<E>,&ThreadQueue<E>::ThreadQueueLoop>,this)
{
}
template <class E>
ThreadQueue<E>::~ThreadQueue()
{
  m_Thread.Cancel();
}
template <class E>
void* ThreadQueue<E>::ThreadQueueLoop()
{
  for(;;)
  {
    E* ptrElement;
    TimeSpan ETA(0,0);
    ptrElement = TryDequeue(&ETA);
    if(ptrElement==0) { // Queue Is Empty
      if(m_Finished) return this;
      //cout << "Queue is empty, waiting for entries." << endl;
      m_QueueEvent.Wait();
      continue; 
    }
    //cout << "Next element ready in " << ETA.Seconds() << " seconds. " << endl;
    if(ETA > TimeSpan::Zero) // Top element not ready
    {
      //cout << "Waiting for " << ETA.Seconds() << " seconds. " << endl;
      m_QueueEvent.Wait(ptrElement->Deadline());
      continue;
    }
    //cout << "Element ready. Executing. " << endl;
    (*ptrElement)();
  } 
  return this;
}
template <class E>
void ThreadQueue<E>::Enqueue(E* newElement)
{
  Lock queueLock(m_QueueLock);
  m_Queue.push(newElement);
  m_QueueEvent.Signal();
}
template <class E>
E* ThreadQueue<E>::TryDequeue(TimeSpan* ETA)
{
  Lock queueLock(m_QueueLock);
  *ETA = TimeSpan(0,0);
  if(m_Queue.empty()) return 0;
  E* nextElement = m_Queue.top();
  if(nextElement!=0) {
    *ETA = -(DateTime::Now() - nextElement->Deadline());
    if(*ETA <= TimeSpan::Zero) m_Queue.pop();
  }
  return nextElement;
}
template <class E>
E* ThreadQueue<E>::Dequeue()
{
  Lock queueLock(m_QueueLock);
  if(m_Queue.empty()) return 0;
  E* nextElement = m_Queue.top();
  m_Queue.pop();
  return nextElement;
}
template <class E>
void ThreadQueue<E>::Finish()
{
  m_Finished = true;
}
template <class E>
void ThreadQueue<E>::Wait()
{
  void *result;
  m_Thread.Join(&result);
}

#endif
