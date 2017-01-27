OBJS_10_2_3 = problem.10.3.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_10_2_3

test_10_2_3 : $(OBJS_10_2_3)
	$(CC) $(LFLAGS) $(OBJS_10_2_3) -o test_10_2_3

problem.10.3.o : problem.10.3.cpp median.hpp
	$(CC) $(CFLAGS) problem.10.3.cpp

clean:
	\rm -rf *.o
