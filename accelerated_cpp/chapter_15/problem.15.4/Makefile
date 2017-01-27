OBJS_15_4 = problem.15.4.o Picture.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_15_4

test_15_4 : $(OBJS_15_4)
	$(CC) $(LFLAGS) $(OBJS_15_4) -o test_15_4

Picture.o : Picture.cpp Picture.hpp Ptr.hpp RefCount.hpp
	$(CC) $(CFLAGS) Picture.cpp

problem.15.4.o : problem.15.4.cpp Picture.hpp Ptr.hpp RefCount.hpp
	$(CC) $(CFLAGS) problem.15.4.cpp


clean:
	\rm -rf *.o
