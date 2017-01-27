OBJS_7_8 = problem.7.8.o urls.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_8

test_7_8 : $(OBJS_7_8)
	$(CC) $(LFLAGS) $(OBJS_7_8) -o test_7_8

problem.7.8.o : problem.7.8.cpp urls.hpp
	$(CC) $(CFLAGS) problem.7.8.cpp

urls.o : urls.cpp urls.hpp
	$(CC) $(CFLAGS) urls.cpp

clean:
	\rm -rf *.o
