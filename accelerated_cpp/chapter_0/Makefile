OBJS_0_0 = problem.0.0.o
OBJS_0_2 = problem.0.2.o
OBJS_0_4 = problem.0.4.o
OBJS_0_5 = problem.0.5.o
OBJS_0_6 = problem.0.6.o
OBJS_0_7 = problem.0.7.o
OBJS_0_8 = problem.0.8.o
OBJS_0_10 = problem.0.10.o
OBJS_valid = valid.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

#problem.0.5.cpp and problem.0.7.cpp aren't valid but were coded to illustrate the errors.  compile separately or uncomment the line below (and comment out the 2nd definition of all) to test.  try to find the errors before testing.
#all : test_0_5 test_0_7
all : test_0_0 test_0_2 test_0_4 test_0_6 test_0_8 test_0_10 test_valid

test_0_0 : $(OBJS_0_0)
	$(CC) $(LFLAGS) $(OBJS_0_0) -o test_0_0

test_0_2 : $(OBJS_0_2)
	$(CC) $(LFLAGS) $(OBJS_0_2) -o test_0_2

test_0_4 : $(OBJS_0_4)
	$(CC) $(LFLAGS) $(OBJS_0_4) -o test_0_4

test_0_5 : $(OBJS_0_5)
	$(CC) $(LFLAGS) $(OBJS_0_5) -o test_0_5

test_0_6 : $(OBJS_0_6)
	$(CC) $(LFLAGS) $(OBJS_0_6) -o test_0_6

test_0_7 : $(OBJS_0_7)
	$(CC) $(LFLAGS) $(OBJS_0_7) -o test_0_7

test_0_8 : $(OBJS_0_8)
	$(CC) $(LFLAGS) $(OBJS_0_8) -o test_0_8

test_0_10 : $(OBJS_0_10)
	$(CC) $(LFLAGS) $(OBJS_0_10) -o test_0_10

test_valid : $(OBJS_valid)
	$(CC) $(LFLAGS) $(OBJS_valid) -o test_valid

problem.0.0.o : problem.0.0.cpp
	$(CC) $(CFLAGS) problem.0.0.cpp

problem.0.2.o : problem.0.2.cpp
	$(CC) $(CFLAGS) problem.0.2.cpp

problem.0.4.o : problem.0.4.cpp
	$(CC) $(CFLAGS) problem.0.4.cpp

problem.0.5.o : problem.0.5.cpp
	$(CC) $(CFLAGS) problem.0.5.cpp

problem.0.6.o : problem.0.6.cpp
	$(CC) $(CFLAGS) problem.0.6.cpp

problem.0.7.o : problem.0.7.cpp
	$(CC) $(CFLAGS) problem.0.7.cpp

problem.0.8.o : problem.0.8.cpp
	$(CC) $(CFLAGS) problem.0.8.cpp

problem.0.10.o : problem.0.10.cpp
	$(CC) $(CFLAGS) problem.0.10.cpp

valid.o : valid.cpp
	$(CC) $(CFLAGS) valid.cpp

clean:
	\rm -rf *.o
