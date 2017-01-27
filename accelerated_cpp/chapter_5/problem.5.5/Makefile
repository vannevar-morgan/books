OBJS_5_5 = problem.5.5.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_5

test_5_5 : $(OBJS_5_5)
	$(CC) $(LFLAGS) $(OBJS_5_5) -o test_5_5

problem.5.5.o : problem.5.5.cpp
	$(CC) $(CFLAGS) problem.5.5.cpp

clean:
	\rm -rf *.o
