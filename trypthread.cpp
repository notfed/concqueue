#include <pthread>
#include <iostream>
int main()
{
  pthread_t myThread;
  pthread_create(&myThread, 0, threadMain, 0);
  pthread_join(myThread,0);
  return 0;
}
void threadMain(void*)
{
    cout << "Hello from thread!" << endl;
}
