EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC)	: main.o heap.o util.o
	$(CC) -o $(EXEC) main.o heap.o util.o

main.o	: main.cpp
	$(CC) $(CFLAGS) main.cpp

heap.o	: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

util.o	: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

clean	:
	rm *.o