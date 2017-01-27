OBJS_4_5 = problem.4.5.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_5

test_4_5 : $(OBJS_4_5)
	$(CC) $(LFLAGS) $(OBJS_4_5) -o test_4_5

problem.4.5.o : problem.4.5.cpp
	$(CC) $(CFLAGS) problem.4.5.cpp

clean:
	\rm -rf *.o
