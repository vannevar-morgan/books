OBJS_8_4_1 = problem.8.4.1.o
OBJS_8_4_2 = problem.8.4.2.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_8_4_1 test_8_4_2

test_8_4_1 : $(OBJS_8_4_1)
	$(CC) $(LFLAGS) $(OBJS_8_4_1) -o test_8_4_1

test_8_4_2 : $(OBJS_8_4_2)
	$(CC) $(LFLAGS) $(OBJS_8_4_2) -o test_8_4_2

problem.8.4.1.o : problem.8.4.1.cpp
	$(CC) $(CFLAGS) problem.8.4.1.cpp

problem.8.4.2.o : problem.8.4.2.cpp
	$(CC) $(CFLAGS) problem.8.4.2.cpp

clean:
	\rm -rf *.o
