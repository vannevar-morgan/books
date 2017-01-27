OBJS_7_3 = problem.7.3.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_3

test_7_3 : $(OBJS_7_3)
	$(CC) $(LFLAGS) $(OBJS_7_3) -o test_7_3

problem.7.3.o : problem.7.3.cpp
	$(CC) $(CFLAGS) problem.7.3.cpp

clean:
	\rm -rf *.o
