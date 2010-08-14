#include <pthread.h>
#include <iostream>
using namespace std;
void* threadMain(void*)
{
    cout << "Hello from thread!" << endl;
}
int main()
{
  pthread_t myThread;
  pthread_attr_t myThreadAttr;
  pthread_create(&myThread, 0, threadMain, 0);
  pthread_join(myThread,0);
  return 0;
}
