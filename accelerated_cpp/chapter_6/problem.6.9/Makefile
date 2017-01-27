OBJS_6_9 = problem.6.9.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_6_9

test_6_9 : $(OBJS_6_9)
	$(CC) $(LFLAGS) $(OBJS_6_9) -o test_6_9

problem.6.9.o : problem.6.9.cpp
	$(CC) $(CFLAGS) problem.6.9.cpp

clean:
	\rm -rf *.o
