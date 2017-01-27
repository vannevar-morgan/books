OBJS_6_3_4 = problem.6.3-4.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_6_3_4

test_6_3_4 : $(OBJS_6_3_4)
	$(CC) $(LFLAGS) $(OBJS_6_3_4) -o test_6_3_4

problem.6.3-4.o : problem.6.3-4.cpp
	$(CC) $(CFLAGS) problem.6.3-4.cpp

clean:
	\rm -rf *.o
