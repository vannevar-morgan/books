OBJS_15_1 = problem.15.1.o Picture.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_15_1

test_15_1 : $(OBJS_15_1)
	$(CC) $(LFLAGS) $(OBJS_15_1) -o test_15_1

Picture.o : Picture.cpp Picture.hpp Ptr.hpp
	$(CC) $(CFLAGS) Picture.cpp

problem.15.1.o : problem.15.1.cpp Picture.hpp Ptr.hpp
	$(CC) $(CFLAGS) problem.15.1.cpp


clean:
	\rm -rf *.o
