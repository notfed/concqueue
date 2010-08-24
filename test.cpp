#include "ScheduledMessage.h"
#include "ThreadQueue.h"
#include "DateTime.h"
#include <pthread.h>
#include <iostream>
using namespace std;
int main()
{
  ThreadQueue<ScheduledMessage> q;
  DateTime now(DateTime::Now());
  ScheduledMessage a("Hi, I'm aaron", now+TimeSpan(1,0));
  ScheduledMessage b("Hi, I'm bob", now+TimeSpan(2,0));
  ScheduledMessage c("Hi, I'm chris", now+TimeSpan(3,0));
  ScheduledMessage d("Hi, I'm david", now+TimeSpan(4,0));
  ScheduledMessage e("Hi, I'm earl", now+TimeSpan(5,0));
  ScheduledMessage f("Hi, I'm frank", now+TimeSpan(6,0));
  ScheduledMessage g("Hi, I'm greg", now+TimeSpan(7,0));
  ScheduledMessage h("Hi, I'm han", now+TimeSpan(8,0));
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
