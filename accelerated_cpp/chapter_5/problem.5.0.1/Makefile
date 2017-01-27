OBJS = problem.5.0.1.o grade.o median.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

problem.5.0.1.o : problem.5.0.1.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.5.0.1.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
