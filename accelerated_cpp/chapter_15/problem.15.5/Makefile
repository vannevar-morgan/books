OBJS_15_5 = problem.15.5.o Picture.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_15_5

test_15_5 : $(OBJS_15_5)
	$(CC) $(LFLAGS) $(OBJS_15_5) -o test_15_5

Picture.o : Picture.cpp Picture.hpp Ptr.hpp RefCount.hpp
	$(CC) $(CFLAGS) Picture.cpp

problem.15.5.o : problem.15.5.cpp Picture.hpp Ptr.hpp RefCount.hpp
	$(CC) $(CFLAGS) problem.15.5.cpp


clean:
	\rm -rf *.o
