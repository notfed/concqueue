#ifndef ROOM_H
#define ROOM_H
#include "Person.h"
#include "Room.h"
#include "Mutex.h"
#include "Thread.h"
#include "Event.h"
#include "DateTime.h"
#include "ThreadQueue.h"
#include "ActionWithDeadline.h"
#include <queue>
#include <vector>
class Room : public ThreadQueue<Person>
{
public:
  Room();
  virtual ~Room();
};
#endif
