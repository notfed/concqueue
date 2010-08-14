CC=g++
trypthread : trypthread.o
	$(CC) -o trypthread trypthread.o 
trypthread.o : trypthread.cpp
	$(CC) -c trypthread.cpp 
