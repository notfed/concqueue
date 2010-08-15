LD=g++ -lpthread -Wall
CC=g++ -Wall
trypthread : trypthread.o Person.o Room.o Lock.o Mutex.o
	$(LD) -o trypthread trypthread.o Person.o Room.o Lock.o Mutex.o
trypthread.o : trypthread.cpp
	$(CC) -c trypthread.cpp 
Person.o : Person.cpp Person.h
	$(CC) -c Person.cpp 
Room.o : Room.cpp Room.h Person.h Mutex.h
	$(CC) -c Room.cpp 
Lock.o : Lock.cpp Lock.h Mutex.h
	$(CC) -c Lock.cpp 
Mutex.o : Mutex.cpp Mutex.h
	$(CC) -c Mutex.cpp 
clean :
	rm -f trypthread *.o
