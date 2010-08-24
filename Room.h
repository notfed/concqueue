#ifndef ROOM_H
#define ROOM_H
#include "Person.h"
#include "Room.h"
#include "Mutex.h"
#include "Thread.h"
#include "Event.h"
#include "DateTime.h"
#include "ActionWithDeadline.h"
#include <queue>
#include <vector>
class Room
{
  volatile bool m_Finished;
  Thread m_Thread;
  std::priority_queue<Person*,std::vector<Person*>,Person::PtrCompareType> m_Queue;
  Mutex m_QueueLock;
  Event m_QueueEvent;
  Person* Dequeue();
  Person* TryDequeue(TimeSpan*);
  void* RoomLoop();
public:
  Room();
  ~Room();
  void Enqueue(Person*); // Add a person to the queue
  void Finish(); // Signal that no more people will be Enqueued
  void Wait(); // Wait for room to finish handling all people currently queued
};
#endif
