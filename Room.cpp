#include "Person.h"
#include "Room.h"
#include "Lock.h"
#include <queue>
#include <functional>
using namespace std;
Room::Room()
{
  pthread_create(&m_Thread, 0, &CallRoomLoop, this);
}
Room::~Room()
{
  pthread_cancel(m_Thread);
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
    if(ptrPerson==0) { WaitForQueue(); continue; }
    ptrPerson->SayHi();
  } 
  return this;
}
void Room::WaitForQueue()
{
  Lock queueLock(m_PersonInQueueWaitMutex);
  pthread_cond_wait(&m_PersonInQueue,&m_PersonInQueueWaitMutex);
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
void Room::Wait()
{
  void *result;
  pthread_join(m_Thread,&result);
}
