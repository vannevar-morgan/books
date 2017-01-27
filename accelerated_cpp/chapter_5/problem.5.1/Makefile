OBJS_5_1 = problem.5.1.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_1

test_5_1 : $(OBJS_5_1)
	$(CC) $(LFLAGS) $(OBJS_5_1) -o test_5_1

problem.5.1.o : problem.5.1.cpp
	$(CC) $(CFLAGS) problem.5.1.cpp

clean:
	\rm -rf *.o
