OBJS_8_3 = problem.8.3.o
OBJS_MAKE_TEST_DATA = make_test_data.o
CC = g++
CFLAGS = -c -Wall -std=c++1y
LFLAGS = -Wall

all : test_8_3 make_test_data

test_8_3 : $(OBJS_8_3)
	$(CC) $(LFLAGS) $(OBJS_8_3) -o test_8_3

make_test_data : $(OBJS_MAKE_TEST_DATA)
	$(CC) $(LFLAGS) $(OBJS_MAKE_TEST_DATA) -o make_test_data

problem.8.3.o : problem.8.3.cpp
	$(CC) $(CFLAGS) problem.8.3.cpp

make_test_data.o : make_test_data.cpp
	$(CC) $(CFLAGS) make_test_data.cpp

clean:
	\rm -rf *.o
