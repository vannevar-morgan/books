OBJS_7_2 = problem.7.2.o grade.o median.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_2

test_7_2 : $(OBJS_7_2)
	$(CC) $(LFLAGS) $(OBJS_7_2) -o test_7_2

problem.7.2.o : problem.7.2.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.7.2.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
