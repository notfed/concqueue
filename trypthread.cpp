#include "Room.h"
#include "Person.h"
#include <pthread.h>
#include <iostream>
using namespace std;
int main()
{
  Room myRoom;
  Person aaron("aaron");
  Person bob("bob");
  Person chris("chris");
  myRoom.Enqueue(&aaron);
  myRoom.Enqueue(&bob);
  myRoom.Enqueue(&chris);
  myRoom.Wait();
  return 0;
}
