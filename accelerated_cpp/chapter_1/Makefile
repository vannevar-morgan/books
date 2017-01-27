OBJS_1_0_1 = problem.1.0.1.o
OBJS_1_0_2 = problem.1.0.2.o
OBJS_1_1 = problem.1.1.o
OBJS_1_2 = problem.1.2.o
OBJS_1_3 = problem.1.3.o
OBJS_1_4 = problem.1.4.o
OBJS_1_5 = problem.1.5.o
OBJS_1_6 = problem.1.6.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

#problem.1.2.cpp and problem.1.5.cpp aren't valid but were coded to illustrate the errors.  compile separately or uncomment the line below (and comment out the 2nd definition of all) to test.  try to find the errors before testing.
#all : test_1_2 test_1_5
all : test_1_0_1 test_1_0_2 test_1_1 test_1_3 test_1_4 test_1_6

test_1_0_1 : $(OBJS_1_0_1)
	$(CC) $(LFLAGS) $(OBJS_1_0_1) -o test_1_0_1

test_1_0_2 : $(OBJS_1_0_2)
	$(CC) $(LFLAGS) $(OBJS_1_0_2) -o test_1_0_2

test_1_1 : $(OBJS_1_1)
	$(CC) $(LFLAGS) $(OBJS_1_1) -o test_1_1

test_1_2 : $(OBJS_1_2)
	$(CC) $(LFLAGS) $(OBJS_1_2) -o test_1_2

test_1_3 : $(OBJS_1_3)
	$(CC) $(LFLAGS) $(OBJS_1_3) -o test_1_3

test_1_4 : $(OBJS_1_4)
	$(CC) $(LFLAGS) $(OBJS_1_4) -o test_1_4

test_1_5 : $(OBJS_1_5)
	$(CC) $(LFLAGS) $(OBJS_1_5) -o test_1_5

test_1_6 : $(OBJS_1_6)
	$(CC) $(LFLAGS) $(OBJS_1_6) -o test_1_6

problem.1.0.1.o : problem.1.0.1.cpp
	$(CC) $(CFLAGS) problem.1.0.1.cpp

problem.1.0.2.o : problem.1.0.2.cpp
	$(CC) $(CFLAGS) problem.1.0.2.cpp

problem.1.1.o : problem.1.1.cpp
	$(CC) $(CFLAGS) problem.1.1.cpp

problem.1.2.o : problem.1.2.cpp
	$(CC) $(CFLAGS) problem.1.2.cpp

problem.1.3.o : problem.1.3.cpp
	$(CC) $(CFLAGS) problem.1.3.cpp

problem.1.4.o : problem.1.4.cpp
	$(CC) $(CFLAGS) problem.1.4.cpp

problem.1.5.o : problem.1.5.cpp
	$(CC) $(CFLAGS) problem.1.5.cpp

problem.1.6.o : problem.1.6.cpp
	$(CC) $(CFLAGS) problem.1.6.cpp

clean:
	\rm -rf *.o
