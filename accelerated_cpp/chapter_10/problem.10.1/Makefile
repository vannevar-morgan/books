OBJS_10_1 = problem.10.1.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_10_1

test_10_1 : $(OBJS_10_1)
	$(CC) $(LFLAGS) $(OBJS_10_1) -o test_10_1

problem.10.1.o : problem.10.1.cpp Student_info.hpp
	$(CC) $(CFLAGS) problem.10.1.cpp

Student_info.o : Student_info.cpp Student_info.hpp
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
