OBJS_8_0_1 = problem.8.0.1.o
OBJS_8_0_2 = problem.8.0.2.o
OBJS_8_0_3 = problem.8.0.3.o
OBJS_8_0_4 = problem.8.0.4.o
OBJS_8_0_5 = problem.8.0.5.o
OBJS_8_0_6 = problem.8.0.6.o
OBJS_8_0_7 = problem.8.0.7.o
OBJS_8_0_8 = problem.8.0.8.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_8_0_1 test_8_0_2 test_8_0_3 test_8_0_4 test_8_0_5 test_8_0_6 test_8_0_7 test_8_0_8

test_8_0_1 : $(OBJS_8_0_1)
	$(CC) $(LFLAGS) $(OBJS_8_0_1) -o test_8_0_1

test_8_0_2 : $(OBJS_8_0_2)
	$(CC) $(LFLAGS) $(OBJS_8_0_2) -o test_8_0_2

test_8_0_3 : $(OBJS_8_0_3)
	$(CC) $(LFLAGS) $(OBJS_8_0_3) -o test_8_0_3

test_8_0_4 : $(OBJS_8_0_4)
	$(CC) $(LFLAGS) $(OBJS_8_0_4) -o test_8_0_4

test_8_0_5 : $(OBJS_8_0_5)
	$(CC) $(LFLAGS) $(OBJS_8_0_5) -o test_8_0_5

test_8_0_6 : $(OBJS_8_0_6)
	$(CC) $(LFLAGS) $(OBJS_8_0_6) -o test_8_0_6

test_8_0_7 : $(OBJS_8_0_7)
	$(CC) $(LFLAGS) $(OBJS_8_0_7) -o test_8_0_7

test_8_0_8 : $(OBJS_8_0_8)
	$(CC) $(LFLAGS) $(OBJS_8_0_8) -o test_8_0_8

problem.8.0.1.o : problem.8.0.1.cpp
	$(CC) $(CFLAGS) problem.8.0.1.cpp

problem.8.0.2.o : problem.8.0.2.cpp
	$(CC) $(CFLAGS) problem.8.0.2.cpp

problem.8.0.3.o : problem.8.0.3.cpp
	$(CC) $(CFLAGS) problem.8.0.3.cpp

problem.8.0.4.o : problem.8.0.4.cpp
	$(CC) $(CFLAGS) problem.8.0.4.cpp

problem.8.0.5.o : problem.8.0.5/problem.8.0.5.cpp
	$(CC) $(CFLAGS) problem.8.0.5/problem.8.0.5.cpp

problem.8.0.6.o : problem.8.0.6.cpp
	$(CC) $(CFLAGS) problem.8.0.6.cpp

problem.8.0.7.o : problem.8.0.7.cpp
	$(CC) $(CFLAGS) problem.8.0.7.cpp

problem.8.0.8.o : problem.8.0.8.cpp
	$(CC) $(CFLAGS) problem.8.0.8.cpp


clean:
	\rm -rf *.o
