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
   Person bob("bob", now+TimeSpan(2,0));
  Person aaron("aaron", now+TimeSpan(1,0));
     Person david("david", now+TimeSpan(4,0));
       Person han("han", now+TimeSpan(8,0));
    Person chris("chris", now+TimeSpan(3,0));
     Person earl("earl", now+TimeSpan(5,0));
      Person frank("frank", now+TimeSpan(6,0));
      Person greg("greg", now+TimeSpan(7,0));
  myRoom.Enqueue(&aaron);
  myRoom.Enqueue(&bob);
  myRoom.Enqueue(&chris);
  myRoom.Enqueue(&david);
  myRoom.Enqueue(&earl);
  myRoom.Enqueue(&frank);
  myRoom.Enqueue(&greg);
  myRoom.Enqueue(&han);
  myRoom.Finish();
  myRoom.Wait();
  return 0;
}
