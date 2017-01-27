OBJS = problem.8.1.o grade.o analysis_schemes.o median.o average.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

problem.8.1.o : problem.8.1.cpp Student_info.h analysis_schemes.h analysis.h
	$(CC) $(CFLAGS) problem.8.1.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

analysis_schemes.o : analysis_schemes.cpp analysis_schemes.h Student_info.h grade.h average.h median.h
	$(CC) $(CFLAGS) analysis_schemes.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

average.o : average.cpp average.h
	$(CC) $(CFLAGS) average.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
