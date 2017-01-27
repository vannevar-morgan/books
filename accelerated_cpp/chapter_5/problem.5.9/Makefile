OBJS_5_9 = problem.5.9.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_9

test_5_9 : $(OBJS_5_9)
	$(CC) $(LFLAGS) $(OBJS_5_9) -o test_5_9

problem.5.9.o : problem.5.9.cpp
	$(CC) $(CFLAGS) problem.5.9.cpp

clean:
	\rm -rf *.o
