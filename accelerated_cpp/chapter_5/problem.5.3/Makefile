OBJS_5_3 = problem.5.3.o grade.o median.o Student_info.o
OBJS_MAKE_TEST_FILES = make_test_files.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_3 makeTestFiles

test_5_3 : $(OBJS_5_3)
	$(CC) $(LFLAGS) $(OBJS_5_3) -o test_5_3

makeTestFiles : $(OBJS_MAKE_TEST_FILES)
	$(CC) $(LFLAGS) $(OBJS_MAKE_TEST_FILES) -o makeTestFiles

make_test_files.o : make_test_files.cpp
	$(CC) $(CFLAGS) make_test_files.cpp

problem.5.3.o : problem.5.3.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.5.3.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
