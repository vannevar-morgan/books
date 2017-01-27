OBJS_TEST_VEC = test_vec.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_vec

test_vec : $(OBJS_TEST_VEC)
	$(CC) $(LFLAGS) $(OBJS_TEST_VEC) -o test_vec

test_vec.o : test_vec.cpp Vec.hpp
	$(CC) $(CFLAGS) test_vec.cpp

clean:
	\rm -rf *.o
