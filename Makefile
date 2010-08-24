LD=g++ -lpthread -Wall
CC=g++ -Wall
try : try.o Lock.o Mutex.o Cond.o Attr.o Thread.o Event.o DateTime.o TimeSpan.o ScheduledMessage.o ActionWithDeadline.o
	$(LD) -o try try.o Lock.o Mutex.o Cond.o Attr.o Thread.o Event.o DateTime.o TimeSpan.o ScheduledMessage.o ActionWithDeadline.o
test : try
	valgrind --tool=helgrind ./try
try.o : try.cpp
	$(CC) -c try.cpp 
Lock.o : Lock.cpp Lock.h Mutex.h
	$(CC) -c Lock.cpp 
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
clean :
	rm -f try *.o
