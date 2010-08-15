#ifndef ROOM_H
#define ROOM_H
#include "Person.h"
#include "Room.h"
#include "Mutex.h"
#include "Thread.h"
#include "Event.h"
#include <queue>
#include <pthread.h>
class Room
{
  volatile bool m_Finished;
  Thread m_Thread;
  std::queue<Person*> m_Queue;
  Mutex m_QueueLock;
  Event m_PersonInQueue;
  Person* Dequeue();
  static void* CallRoomLoop(void*);
  void* RoomLoop();
public:
  Room();
  ~Room();
  void Enqueue(Person*); // Add a person to the queue
  void Finish(); // Signal that no more people will be Enqueued
  void Wait(); // Wait for room to finish handling all people currently queued
};
#endif
