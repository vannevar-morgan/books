OBJS_2_0_1 = problem.2.0.1.o
OBJS_2_1 = problem.2.1.o
OBJS_2_2 = problem.2.2.o
OBJS_2_3 = problem.2.3.o
OBJS_2_4 = problem.2.4.o
OBJS_2_5 = problem.2.5.o
OBJS_2_6 = problem.2.6.o
OBJS_2_7 = problem.2.7.o
OBJS_2_8 = problem.2.8.o
OBJS_2_9 = problem.2.9.o
OBJS_2_10 = problem.2.10.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_2_0_1 test_2_1 test_2_2 test_2_3 test_2_4 test_2_5 test_2_6 test_2_7 test_2_8 test_2_9 test_2_10

test_2_0_1 : $(OBJS_2_0_1)
	$(CC) $(LFLAGS) $(OBJS_2_0_1) -o test_2_0_1

test_2_1 : $(OBJS_2_1)
	$(CC) $(LFLAGS) $(OBJS_2_1) -o test_2_1

test_2_2 : $(OBJS_2_2)
	$(CC) $(LFLAGS) $(OBJS_2_2) -o test_2_2

test_2_3 : $(OBJS_2_3)
	$(CC) $(LFLAGS) $(OBJS_2_3) -o test_2_3

test_2_4 : $(OBJS_2_4)
	$(CC) $(LFLAGS) $(OBJS_2_4) -o test_2_4

test_2_5 : $(OBJS_2_5)
	$(CC) $(LFLAGS) $(OBJS_2_5) -o test_2_5

test_2_6 : $(OBJS_2_6)
	$(CC) $(LFLAGS) $(OBJS_2_6) -o test_2_6

test_2_7 : $(OBJS_2_7)
	$(CC) $(LFLAGS) $(OBJS_2_7) -o test_2_7

test_2_8 : $(OBJS_2_8)
	$(CC) $(LFLAGS) $(OBJS_2_8) -o test_2_8

test_2_9 : $(OBJS_2_9)
	$(CC) $(LFLAGS) $(OBJS_2_9) -o test_2_9

test_2_10 : $(OBJS_2_10)
	$(CC) $(LFLAGS) $(OBJS_2_10) -o test_2_10

problem.2.0.1.o : problem.2.0.1.cpp
	$(CC) $(CFLAGS) problem.2.0.1.cpp

problem.2.1.o : problem.2.1.cpp
	$(CC) $(CFLAGS) problem.2.1.cpp

problem.2.2.o : problem.2.2.cpp
	$(CC) $(CFLAGS) problem.2.2.cpp

problem.2.3.o : problem.2.3.cpp
	$(CC) $(CFLAGS) problem.2.3.cpp

problem.2.4.o : problem.2.4.cpp
	$(CC) $(CFLAGS) problem.2.4.cpp

problem.2.5.o : problem.2.5.cpp
	$(CC) $(CFLAGS) problem.2.5.cpp

problem.2.6.o : problem.2.6.cpp
	$(CC) $(CFLAGS) problem.2.6.cpp

problem.2.7.o : problem.2.7.cpp
	$(CC) $(CFLAGS) problem.2.7.cpp

problem.2.8.o : problem.2.8.cpp
	$(CC) $(CFLAGS) problem.2.8.cpp

problem.2.9.o : problem.2.9.cpp
	$(CC) $(CFLAGS) problem.2.9.cpp

problem.2.10.o : problem.2.10.cpp
	$(CC) $(CFLAGS) problem.2.10.cpp

clean:
	\rm -rf *.o
