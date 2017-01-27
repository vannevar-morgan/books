OBJS_VECTOR = problem.5.2.vector.o grade.o median.o Student_info.o
OBJS_LIST = problem.5.2.list.o grade.o median.o Student_info.o
OBJS_MAKE_TEST_FILES = make_test_files.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_vector test_list makeTestFiles

test_vector : $(OBJS_VECTOR)
	$(CC) $(LFLAGS) $(OBJS_VECTOR) -o test_vector

test_list : $(OBJS_LIST)
	$(CC) $(LFLAGS) $(OBJS_LIST) -o test_list

makeTestFiles : $(OBJS_MAKE_TEST_FILES)
	$(CC) $(LFLAGS) $(OBJS_MAKE_TEST_FILES) -o makeTestFiles

make_test_files.o : make_test_files.cpp
	$(CC) $(CFLAGS) make_test_files.cpp

problem.5.2.vector.o : problem.5.2.vector.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.5.2.vector.cpp

problem.5.2.list.o : problem.5.2.list.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.5.2.list.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
