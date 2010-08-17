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
  Person a("aaron", now+TimeSpan(1,0));
  Person b("bob", now+TimeSpan(2,0));
  Person c("chris", now+TimeSpan(3,0));
  Person d("david", now+TimeSpan(4,0));
  Person e("earl", now+TimeSpan(5,0));
  Person f("frank", now+TimeSpan(6,0));
  Person g("greg", now+TimeSpan(7,0));
  Person h("han", now+TimeSpan(8,0));
  myRoom.Enqueue(&h);
  myRoom.Enqueue(&e);
  myRoom.Enqueue(&a);
  myRoom.Enqueue(&c);
  myRoom.Enqueue(&d);
  myRoom.Enqueue(&f);
  myRoom.Enqueue(&b);
  myRoom.Enqueue(&g);
  myRoom.Finish();
  myRoom.Wait();
  return 0;
}
