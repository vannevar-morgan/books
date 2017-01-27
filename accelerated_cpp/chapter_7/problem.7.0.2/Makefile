OBJS_7_0_2 = problem.7.0.2.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_0_2

test_7_0_2 : $(OBJS_7_0_2)
	$(CC) $(LFLAGS) $(OBJS_7_0_2) -o test_7_0_2

problem.7.0.2.o : problem.7.0.2.cpp
	$(CC) $(CFLAGS) problem.7.0.2.cpp

clean:
	\rm -rf *.o
