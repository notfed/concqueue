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
    m_Thread(&CallRoomLoop<Room>,this)
{
}
Room::~Room()
{
  m_Thread.Cancel();
}
void* Room::RoomLoop()
{
  Person* ptrPerson;
  for(;;)
  {
    ptrPerson = Dequeue();
    if(ptrPerson==0) { 
      if(m_Finished) return this;
      m_PersonInQueue.Wait();
      continue; 
    }
    ptrPerson->SayHi();
  } 
  return this;
}

void Room::Enqueue(Person* newPerson)
{
  Lock queueLock(m_QueueLock);
  m_Queue.push(newPerson);
  m_PersonInQueue.Signal();
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
