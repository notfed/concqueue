LD=g++ -lpthread -Wall
CC=g++ -Wall
try : try.o Mutex.o Cond.o Attr.o Thread.o Event.o DateTime.o TimeSpan.o ScheduledMessage.o ActionWithDeadline.o Semaphore.o MutexAttr.o
	$(LD) -o try try.o Mutex.o Cond.o Attr.o Thread.o Event.o DateTime.o TimeSpan.o ScheduledMessage.o ActionWithDeadline.o Semaphore.o MutexAttr.o
helgrind-fast : try
	valgrind --tool=helgrind ./try
helgrind : try
	valgrind --tool=helgrind --read-var-info=yes ./try
drd : try
	valgrind --tool=drd ./try
memcheck-fast : try
	valgrind --tool=memcheck --track-origins=yes ./try
memcheck : try
	valgrind --tool=memcheck --track-origins=yes --read-var-info=yes ./try
try.o : try.cpp
	$(CC) -c try.cpp 
Mutex.o : Mutex.cpp Mutex.h
	$(CC) -c Mutex.cpp 
Cond.o : Cond.cpp Cond.h
	$(CC) -c Cond.cpp 
Attr.o : Attr.cpp Attr.h
	$(CC) -c Attr.cpp 
Thread.o : Thread.cpp Thread.h
	$(CC) -c Thread.cpp 
Event.o : Event.cpp Event.h Mutex.h
	$(CC) -c Event.cpp 
DateTime.o : DateTime.cpp DateTime.h TimeSpan.h
	$(CC) -c DateTime.cpp
TimeSpan.o : TimeSpan.cpp TimeSpan.h
	$(CC) -c TimeSpan.cpp
ScheduledMessage.o : ScheduledMessage.cpp ScheduledMessage.h
	$(CC) -c ScheduledMessage.cpp
ActionWithDeadline.o : ActionWithDeadline.cpp ActionWithDeadline.h
	$(CC) -c ActionWithDeadline.cpp
Semaphore.o : Semaphore.cpp Semaphore.h
	$(CC) -c Semaphore.cpp
MutexAttr.o : MutexAttr.cpp MutexAttr.h
	$(CC) -c MutexAttr.cpp
clean :
	rm -f try *.o
