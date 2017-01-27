OBJS_16_1 = problem.16.1.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_16_1

test_16_1 : $(OBJS_16_1)
	$(CC) $(LFLAGS) $(OBJS_16_1) -o test_16_1

problem.16.1.o : problem.16.1.cpp
	$(CC) $(CFLAGS) problem.16.1.cpp

clean:
	\rm -rf *.o
