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
class ActionQueueBase
{
protected:
  Semaphore m_QueueLock;
  Semaphore m_FinishedLock;
  Event m_QueueEvent;
  std::priority_queue<E*,std::vector<E*>,typename E::PtrCompareType> m_Queue;
};

template <class E> // where E : ActionWithDeadline
class ActionQueue : private ActionQueueBase<E>
{
  volatile bool m_Finished;
  Thread m_Thread;
  E* Dequeue();
  E* TryDequeue(TimeSpan*);
  void* ActionQueueLoop();
public:
  virtual ~ActionQueue();
  ActionQueue();
  void Enqueue(E*); // Add an element to the queue
  void Finish(); // Signal that no more elements will be Enqueued
  bool Finished(); // Check whether Finish has been called
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
    {
      Lock<Semaphore> qlock(this->m_QueueLock);
      ptrElement = TryDequeue(&ETA);
    }
    if(ptrElement==0) { // Queue Is Empty
      if(Finished()) {
        //cout << "Queue is empty, finished." << endl;
        break;
      }
      //cout << "Queue is empty, waiting for entries." << endl;
      this->m_QueueEvent.Wait();
      continue; 
    }
    //cout << "Next element ready in " << ETA.Seconds() << " seconds. " << endl;
    if(ETA > TimeSpan::Zero) // Top element not ready
    {
      //cout << "Waiting for " << ETA.Seconds() << " seconds. " << endl;
      this->m_QueueEvent.Wait(ptrElement->Deadline());
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
  Lock<Semaphore> queueLock(this->m_QueueLock);
  this->m_Queue.push(newElement);
  this->m_QueueEvent.Signal();
}
template <class E>
E* ActionQueue<E>::TryDequeue(TimeSpan* ETA)
{
  *ETA = TimeSpan(0,0);
  if(this->m_Queue.empty()) return 0;
  E* nextElement = this->m_Queue.top();
  if(nextElement!=0) {
    *ETA = -(DateTime::Now() - nextElement->Deadline());
    if(*ETA <= TimeSpan::Zero) this->m_Queue.pop();
  }
  return nextElement;
}
template <class E>
E* ActionQueue<E>::Dequeue()
{
  Lock<Semaphore> queueLock(this->m_QueueLock);
  if(this->m_Queue.empty()) return 0;
  E* nextElement = this->m_Queue.top();
  this->m_Queue.pop();
  return nextElement;
}
template <class E>
void ActionQueue<E>::Finish()
{
  Lock<Semaphore> g(this->m_FinishedLock);
  m_Finished = true;
}
template <class E>
bool ActionQueue<E>::Finished()
{
  Lock<Semaphore> g(this->m_FinishedLock);
  return m_Finished == true;
}
template <class E>
void ActionQueue<E>::Wait()
{
  m_Thread.Join();
}

#endif
