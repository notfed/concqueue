#ifndef ACTIONQUEUE_H
#define ACTIONQUEUE_H
#include "Semaphore.h"
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

template <class E> // where E : ActionWithDeadline
class ActionQueue
{
  volatile bool m_Finished;
  Thread m_Thread;
  std::priority_queue<E*,std::vector<E*>,typename E::PtrCompareType> m_Queue;
  Semaphore m_QueueLock;
  Event m_QueueEvent;
  E* Dequeue();
  E* TryDequeue(TimeSpan*);
  void* ActionQueueLoop();
public:
  ActionQueue();
  virtual ~ActionQueue();
  void Enqueue(E*); // Add an element to the queue
  void Finish(); // Signal that no more elements will be Enqueued
  void Wait(); // Wait for queue to finish handling all elements currently queued
};

template <class E>
ActionQueue<E>::ActionQueue()
  : m_Finished(false),
    m_Thread(&CallMemFun<ActionQueue<E>,&ActionQueue<E>::ActionQueueLoop>,this)
{
}
template <class E>
ActionQueue<E>::~ActionQueue()
{
  m_Thread.Cancel();
}
template <class E>
void* ActionQueue<E>::ActionQueueLoop()
{
  for(;;)
  {
    E* ptrElement;
    TimeSpan ETA(0,0);
    ptrElement = TryDequeue(&ETA);
    if(ptrElement==0) { // Queue Is Empty
      if(m_Finished) {
        //cout << "Queue is empty, finished." << endl;
        break;
      }
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
void ActionQueue<E>::Enqueue(E* newElement)
{
  Lock<Semaphore> queueLock(m_QueueLock);
  m_Queue.push(newElement);
  m_QueueEvent.Signal();
}
template <class E>
E* ActionQueue<E>::TryDequeue(TimeSpan* ETA)
{
  Lock<Semaphore> queueLock(m_QueueLock);
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
E* ActionQueue<E>::Dequeue()
{
  Lock<Semaphore> queueLock(m_QueueLock);
  if(m_Queue.empty()) return 0;
  E* nextElement = m_Queue.top();
  m_Queue.pop();
  return nextElement;
}
template <class E>
void ActionQueue<E>::Finish()
{
  m_Finished = true;
}
template <class E>
void ActionQueue<E>::Wait()
{
  m_Thread.Join();
}

#endif
