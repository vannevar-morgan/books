OBJS_6_1 = problem.6.1.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_6_1

test_6_1 : $(OBJS_6_1)
	$(CC) $(LFLAGS) $(OBJS_6_1) -o test_6_1

problem.6.1.o : problem.6.1.cpp
	$(CC) $(CFLAGS) problem.6.1.cpp

clean:
	\rm -rf *.o
