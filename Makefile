CC=g++ -lpthread
trypthread : trypthread.o
	$(CC) -o trypthread trypthread.o 
trypthread.o : trypthread.cpp
	$(CC) -c trypthread.cpp 
clean :
	rm -f trypthread trypthread.o
