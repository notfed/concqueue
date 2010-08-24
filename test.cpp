#include "Person.h"
#include "ThreadQueue.h"
#include "DateTime.h"
#include <pthread.h>
#include <iostream>
using namespace std;
int main()
{
  ThreadQueue<Person> q;
  DateTime now(DateTime::Now());
  Person a("aaron", now+TimeSpan(1,0));
  Person b("bob", now+TimeSpan(2,0));
  Person c("chris", now+TimeSpan(3,0));
  Person d("david", now+TimeSpan(4,0));
  Person e("earl", now+TimeSpan(5,0));
  Person f("frank", now+TimeSpan(6,0));
  Person g("greg", now+TimeSpan(7,0));
  Person h("han", now+TimeSpan(8,0));
  q.Enqueue(&h);
  q.Enqueue(&e);
  q.Enqueue(&a);
  q.Enqueue(&c);
  q.Enqueue(&d);
  q.Enqueue(&f);
  q.Enqueue(&b);
  q.Enqueue(&g);
  q.Finish();
  q.Wait();
  return 0;
}
