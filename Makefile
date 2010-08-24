LD=g++ -lpthread -Wall
CC=g++ -Wall
test : test.o Lock.o Mutex.o Thread.o Event.o DateTime.o TimeSpan.o ScheduledMessage.o
	$(LD) -o test test.o Lock.o Mutex.o Thread.o Event.o DateTime.o TimeSpan.o ScheduledMessage.o
test.o : test.cpp
	$(CC) -c test.cpp 
Lock.o : Lock.cpp Lock.h Mutex.h
	$(CC) -c Lock.cpp 
Mutex.o : Mutex.cpp Mutex.h
	$(CC) -c Mutex.cpp 
Cond.o : Cond.cpp Cond.h
	$(CC) -c Mutex.cpp 
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
clean :
	rm -f test *.o
