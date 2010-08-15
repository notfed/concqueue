#ifndef ROOM_H
#define ROOM_H
#include "Person.h"
#include "Room.h"
#include <queue>
#include <pthread.h>
class Room
{
  volatile bool m_Finished;
  pthread_t m_Thread;
  std::queue<Person*> m_Queue;
  pthread_mutex_t m_QueueLock;

  pthread_cond_t m_PersonInQueue;
  pthread_mutex_t m_PersonInQueueMutex;
  pthread_mutex_t m_PersonInQueueWaitMutex;

  Person* Dequeue();
  void WaitForQueue();
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
