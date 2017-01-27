OBJS_5_10 = problem.5.10.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_10

test_5_10 : $(OBJS_5_10)
	$(CC) $(LFLAGS) $(OBJS_5_10) -o test_5_10

problem.5.10.o : problem.5.10.cpp
	$(CC) $(CFLAGS) problem.5.10.cpp

clean:
	\rm -rf *.o
