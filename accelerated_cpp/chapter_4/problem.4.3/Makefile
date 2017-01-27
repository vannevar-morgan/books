OBJS_4_3 = problem.4.3.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_3

test_4_3 : $(OBJS_4_3)
	$(CC) $(LFLAGS) $(OBJS_4_3) -o test_4_3

problem.4.3.o : problem.4.3.cpp
	$(CC) $(CFLAGS) problem.4.3.cpp

clean:
	\rm -rf *.o
