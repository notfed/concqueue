#include "Person.h"
#include "Room.h"
#include "Lock.h"
#include <queue>
#include <functional>
#include <pthread.h>
#include <iostream>
using namespace std;
Room::Room()
  : m_Finished(false),
    m_Thread(&CallRoomLoop,this)
{
  pthread_cond_init(&m_PersonInQueue,0);
}
Room::~Room()
{
  m_Thread.Cancel();
}
void* Room::CallRoomLoop(void* _this)
{
  Room *theRoom = reinterpret_cast<Room*>(_this);
  return theRoom->RoomLoop();
}
void* Room::RoomLoop()
{
  Person* ptrPerson;
  for(;;)
  {
    ptrPerson = Dequeue();
    if(ptrPerson==0) { 
      if(m_Finished) return this;
      WaitForQueue(); 
      continue; 
    }
    ptrPerson->SayHi();
  } 
  return this;
}
void Room::WaitForQueue()
{
  Lock queueLock(m_PersonInQueueWaitMutex);
  pthread_cond_wait(&m_PersonInQueue,m_PersonInQueueWaitMutex);
}

void Room::Enqueue(Person* newPerson)
{
  Lock queueLock(m_QueueLock);
  m_Queue.push(newPerson);
  pthread_cond_signal(&m_PersonInQueue);
}
Person* Room::Dequeue()
{
  Lock queueLock(m_QueueLock);
  if(m_Queue.empty()) return 0;
  Person* nextPerson = m_Queue.front();
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
