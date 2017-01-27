OBJS_4_2 = problem.4.2.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_2

test_4_2 : $(OBJS_4_2)
	$(CC) $(LFLAGS) $(OBJS_4_2) -o test_4_2

problem.4.2.o : problem.4.2.cpp
	$(CC) $(CFLAGS) problem.4.2.cpp

clean:
	\rm -rf *.o
