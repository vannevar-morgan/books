OBJS_4_7 = problem.4.7.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_7

test_4_7 : $(OBJS_4_7)
	$(CC) $(LFLAGS) $(OBJS_4_7) -o test_4_7

problem.4.7.o : problem.4.7.cpp
	$(CC) $(CFLAGS) problem.4.7.cpp

clean:
	\rm -rf *.o
