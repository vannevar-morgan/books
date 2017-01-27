OBJS_4_6 = problem.4.6.o grade.o median.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_4_6

test_4_6 : $(OBJS_4_6)
	$(CC) $(LFLAGS) $(OBJS_4_6) -o test_4_6

problem.4.6.o : problem.4.6.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.4.6.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
