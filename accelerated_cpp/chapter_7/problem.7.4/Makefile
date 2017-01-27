OBJS_7_4 = problem.7.4.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_4

test_7_4 : $(OBJS_7_4)
	$(CC) $(LFLAGS) $(OBJS_7_4) -o test_7_4

problem.7.4.o : problem.7.4.cpp
	$(CC) $(CFLAGS) problem.7.4.cpp

clean:
	\rm -rf *.o
