OBJS_15_2 = problem.15.1.o Picture.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_15_2

test_15_2 : $(OBJS_15_2)
	$(CC) $(LFLAGS) $(OBJS_15_2) -o test_15_2

Picture.o : Picture.cpp Picture.hpp Ptr.hpp
	$(CC) $(CFLAGS) Picture.cpp

problem.15.1.o : problem.15.1.cpp Picture.hpp Ptr.hpp
	$(CC) $(CFLAGS) problem.15.1.cpp


clean:
	\rm -rf *.o
