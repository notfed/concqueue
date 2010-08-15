LD=g++ -lpthread
CC=g++
trypthread : trypthread.o Person.o Room.o Lock.o
	$(LD) -o trypthread trypthread.o Person.o Room.o Lock.o
trypthread.o : trypthread.cpp
	$(CC) -c trypthread.cpp 
Person.o : Person.cpp Person.h
	$(CC) -c Person.cpp 
Room.o : Room.cpp Room.h
	$(CC) -c Room.cpp 
Lock.o : Lock.cpp Lock.h
	$(CC) -c Lock.cpp 
clean :
	rm -f trypthread *.o
