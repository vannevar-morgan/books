OBJS_8_5 = problem.8.5.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_8_5

test_8_5 : $(OBJS_8_5)
	$(CC) $(LFLAGS) $(OBJS_8_5) -o test_8_5

problem.8.5.o : problem.8.5.cpp
	$(CC) $(CFLAGS) problem.8.5.cpp

clean:
	\rm -rf *.o
