#include "Person.h"
#include "Room.h"
#include "Lock.h"
#include "CallMemFun.h"
#include "Thread.h"
#include <queue>
#include <functional>
#include <iostream>
using namespace std;
Room::Room()
  : m_Finished(false),
    m_Thread(&CallMemFun<Room,&Room::RoomLoop>,this)
{
}
Room::~Room()
{
  m_Thread.Cancel();
}
void* Room::RoomLoop()
{
  for(;;)
  {
    Person* ptrPerson;
    TimeSpan ETA(0,0);
    ptrPerson = TryDequeue(&ETA);
    if(ptrPerson==0) { // Queue Is Empty
      if(m_Finished) return this;
      //cout << "Queue is empty, waiting for entries." << endl;
      m_QueueEvent.Wait();
      continue; 
    }
    //cout << "Next person ready in " << ETA.Seconds() << " seconds. " << endl;
    if(ETA > TimeSpan::Zero) // Top element not ready
    {
      //cout << "Waiting for " << ETA.Seconds() << " seconds. " << endl;
      m_QueueEvent.Wait(ptrPerson->Deadline());
      continue;
    }
    //cout << "Element ready. Executing. " << endl;
    (*ptrPerson)();
  } 
  return this;
}

void Room::Enqueue(Person* newPerson)
{
  Lock queueLock(m_QueueLock);
  m_Queue.push(newPerson);
  m_QueueEvent.Signal();
}
Person* Room::TryDequeue(TimeSpan* ETA)
{
  Lock queueLock(m_QueueLock);
  *ETA = TimeSpan(0,0);
  if(m_Queue.empty()) return 0;
  Person* nextPerson = m_Queue.top();
  if(nextPerson!=0) {
    *ETA = -(DateTime::Now() - nextPerson->Deadline());
    if(*ETA <= TimeSpan::Zero) m_Queue.pop();
  }
  return nextPerson;
}
Person* Room::Dequeue()
{
  Lock queueLock(m_QueueLock);
  if(m_Queue.empty()) return 0;
  Person* nextPerson = m_Queue.top();
  m_Queue.pop();
  return nextPerson;
}
void Room::Finish()
{
  m_Finished = true;
}
void Room::Wait()
{
  void *result;
  m_Thread.Join(&result);
}

