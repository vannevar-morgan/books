OBJS_15_3 = problem.15.3.o Picture.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_15_3

test_15_3 : $(OBJS_15_3)
	$(CC) $(LFLAGS) $(OBJS_15_3) -o test_15_3

Picture.o : Picture.cpp Picture.hpp Ptr.hpp
	$(CC) $(CFLAGS) Picture.cpp

problem.15.3.o : problem.15.3.cpp Picture.hpp Ptr.hpp
	$(CC) $(CFLAGS) problem.15.3.cpp


clean:
	\rm -rf *.o
