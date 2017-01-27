OBJS_10_6 = problem.10.6.o String_list.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_10_6

test_10_6 : $(OBJS_10_6)
	$(CC) $(LFLAGS) $(OBJS_10_6) -o test_10_6

problem.10.6.o : problem.10.6.cpp String_list.hpp
	$(CC) $(CFLAGS) problem.10.6.cpp

String_list.o : String_list.cpp String_list.hpp
	$(CC) $(CFLAGS) String_list.cpp

clean:
	\rm -rf *.o
