OBJS_4_1 = problem.4.1.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_1

test_4_1 : $(OBJS_4_1)
	$(CC) $(LFLAGS) $(OBJS_4_1) -o test_4_1

problem.4.1.o : problem.4.1.cpp Student_info.h
	$(CC) $(CFLAGS) problem.4.1.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
