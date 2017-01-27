OBJS_3_0_1 = problem.3.0.1.o
OBJS_3_0_2 = problem.3.0.2.o
OBJS_3_2 = problem.3.2.o
OBJS_3_3 = problem.3.3.o
OBJS_3_4 = problem.3.4.o
OBJS_3_5 = problem.3.5.o
OBJS_3_6 = problem.3.6.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_3_0_1 test_3_0_2 test_3_2 test_3_3 test_3_4 test_3_5 test_3_6

test_3_0_1 : $(OBJS_3_0_1)
	$(CC) $(LFLAGS) $(OBJS_3_0_1) -o test_3_0_1

test_3_0_2 : $(OBJS_3_0_2)
	$(CC) $(LFLAGS) $(OBJS_3_0_2) -o test_3_0_2

test_3_2 : $(OBJS_3_2)
	$(CC) $(LFLAGS) $(OBJS_3_2) -o test_3_2

test_3_3 : $(OBJS_3_3)
	$(CC) $(LFLAGS) $(OBJS_3_3) -o test_3_3

test_3_4 : $(OBJS_3_4)
	$(CC) $(LFLAGS) $(OBJS_3_4) -o test_3_4

test_3_5 : $(OBJS_3_5)
	$(CC) $(LFLAGS) $(OBJS_3_5) -o test_3_5

test_3_6 : $(OBJS_3_6)
	$(CC) $(LFLAGS) $(OBJS_3_6) -o test_3_6

problem.3.0.1.o : problem.3.0.1.cpp
	$(CC) $(CFLAGS) problem.3.0.1.cpp

problem.3.0.2.o : problem.3.0.2.cpp
	$(CC) $(CFLAGS) problem.3.0.2.cpp

problem.3.2.o : problem.3.2.cpp
	$(CC) $(CFLAGS) problem.3.2.cpp

problem.3.3.o : problem.3.3.cpp
	$(CC) $(CFLAGS) problem.3.3.cpp

problem.3.4.o : problem.3.4.cpp
	$(CC) $(CFLAGS) problem.3.4.cpp

problem.3.5.o : problem.3.5.cpp
	$(CC) $(CFLAGS) problem.3.5.cpp

problem.3.6.o : problem.3.6.cpp
	$(CC) $(CFLAGS) problem.3.6.cpp

clean:
	\rm -rf *.o
