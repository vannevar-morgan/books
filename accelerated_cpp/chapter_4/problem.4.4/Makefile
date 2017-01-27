OBJS_4_4 = problem.4.4.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_4

test_4_4 : $(OBJS_4_4)
	$(CC) $(LFLAGS) $(OBJS_4_4) -o test_4_4

problem.4.4.o : problem.4.4.cpp
	$(CC) $(CFLAGS) problem.4.4.cpp

clean:
	\rm -rf *.o
