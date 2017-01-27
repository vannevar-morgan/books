OBJS_7_9 = problem.7.9.o nrand.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_9

test_7_9 : $(OBJS_7_9)
	$(CC) $(LFLAGS) $(OBJS_7_9) -o test_7_9

problem.7.9.o : problem.7.9.cpp nrand.h
	$(CC) $(CFLAGS) problem.7.9.cpp

nrand.o : nrand.cpp nrand.h
	$(CC) $(CFLAGS) nrand.cpp

clean:
	\rm -rf *.o
