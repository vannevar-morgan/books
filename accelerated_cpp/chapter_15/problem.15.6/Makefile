OBJS_15_6 = problem.15.6.o Ptr.o Str.o Picture.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_15_6

test_15_6 : $(OBJS_15_6)
	$(CC) $(LFLAGS) $(OBJS_15_6) -o test_15_6

Ptr.o : Ptr.cpp Ptr.hpp RefCount.hpp Vec.hpp
	$(CC) $(CFLAGS) Ptr.cpp

Str.o : Str.cpp Str.hpp Vec.hpp Ptr.hpp
	$(CC) $(CFLAGS) Str.cpp

Picture.o : Picture.cpp Picture.hpp Ptr.hpp RefCount.hpp Vec.hpp Str.hpp
	$(CC) $(CFLAGS) Picture.cpp

problem.15.6.o : problem.15.6.cpp Picture.hpp Ptr.hpp RefCount.hpp Vec.hpp Str.hpp
	$(CC) $(CFLAGS) problem.15.6.cpp


clean:
	\rm -rf *.o
