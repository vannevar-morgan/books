OBJS_6_0_4 = problem.6.0.4.o analysis_schemes.o average.o grade.o median.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_6_0_4

test_6_0_4 : $(OBJS_6_0_4)
	$(CC) $(LFLAGS) $(OBJS_6_0_4) -o test_6_0_4

problem.6.0.4.o : problem.6.0.4.cpp Student_info.h grade.h analysis_schemes.h
	$(CC) $(CFLAGS) problem.6.0.4.cpp

analysis_schemes.o : analysis_schemes.cpp analysis_schemes.h Student_info.h grade.h average.h median.h
	$(CC) $(CFLAGS) analysis_schemes.cpp

average.o : average.cpp average.h
	$(CC) $(CFLAGS) average.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
