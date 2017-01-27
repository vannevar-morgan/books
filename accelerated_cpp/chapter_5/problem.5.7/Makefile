OBJS_5_7 = problem.5.7.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_7

test_5_7 : $(OBJS_5_7)
	$(CC) $(LFLAGS) $(OBJS_5_7) -o test_5_7

problem.5.7.o : problem.5.7.cpp
	$(CC) $(CFLAGS) problem.5.7.cpp

clean:
	\rm -rf *.o
