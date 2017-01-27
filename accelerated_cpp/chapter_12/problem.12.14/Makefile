OBJS = problem.12.14.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

problem.12.14.o : problem.12.14.cpp Vec.hpp
	$(CC) $(CFLAGS) problem.12.14.cpp

clean:
	\rm -rf *.o
