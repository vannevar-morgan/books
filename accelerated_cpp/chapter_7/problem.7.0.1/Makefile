OBJS_7_0_1 = problem.7.0.1.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_0_1

test_7_0_1 : $(OBJS_7_0_1)
	$(CC) $(LFLAGS) $(OBJS_7_0_1) -o test_7_0_1

problem.7.0.1.o : problem.7.0.1.cpp
	$(CC) $(CFLAGS) problem.7.0.1.cpp

clean:
	\rm -rf *.o
