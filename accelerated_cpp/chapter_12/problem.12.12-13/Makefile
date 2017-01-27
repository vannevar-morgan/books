OBJS_TEST_STR = test_Str.o Str.o
OBJS_TEST_VEC = test_Vec.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_Str test_Vec

test_Str : $(OBJS_TEST_STR)
	$(CC) $(LFLAGS) $(OBJS_TEST_STR) -o test_Str

test_Vec : $(OBJS_TEST_VEC)
	$(CC) $(LFLAGS) $(OBJS_TEST_VEC) -o test_Vec

test_Str.o : test_Str.cpp Str.hpp
	$(CC) $(CFLAGS) test_Str.cpp

test_Vec.o : test_Vec.cpp Vec.hpp
	$(CC) $(CFLAGS) test_Vec.cpp

Str.o : Str.cpp Str.hpp
	$(CC) $(CFLAGS) Str.cpp

clean:
	\rm -rf *.o
