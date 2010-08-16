#include "Room.h"
#include "Person.h"
#include "DateTime.h"
#include <pthread.h>
#include <iostream>
using namespace std;
int main()
{
  Room myRoom;
  DateTime now(DateTime::Now());
  Person aaron("aaron", now+TimeSpan(12,0));
  Person bob("bob", now+TimeSpan(10,0));
  Person chris("chris", now+TimeSpan(15,0));
  myRoom.Enqueue(&aaron);
  myRoom.Enqueue(&bob);
  myRoom.Enqueue(&chris);
  myRoom.Finish();
  myRoom.Wait();
  return 0;
}
