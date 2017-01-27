OBJS_5_8 = problem.5.8.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_8

test_5_8 : $(OBJS_5_8)
	$(CC) $(LFLAGS) $(OBJS_5_8) -o test_5_8

problem.5.8.o : problem.5.8.cpp
	$(CC) $(CFLAGS) problem.5.8.cpp

clean:
	\rm -rf *.o
