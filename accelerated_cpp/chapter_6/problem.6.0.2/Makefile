OBJS_6_0_2 = problem.6.0.2.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : palindrome

palindrome : $(OBJS_6_0_2)
	$(CC) $(LFLAGS) $(OBJS_6_0_2) -o palindrome

problem.6.0.2.o : problem.6.0.2.cpp
	$(CC) $(CFLAGS) problem.6.0.2.cpp

clean:
	\rm -rf *.o
