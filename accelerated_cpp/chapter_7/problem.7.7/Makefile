OBJS_7_7 = problem.7.7.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_7

test_7_7 : $(OBJS_7_7)
	$(CC) $(LFLAGS) $(OBJS_7_7) -o test_7_7

problem.7.7.o : problem.7.7.cpp
	$(CC) $(CFLAGS) problem.7.7.cpp

clean:
	\rm -rf *.o
