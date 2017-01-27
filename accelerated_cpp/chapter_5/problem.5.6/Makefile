OBJS_5_6_RESIZE = problem.5.6_resize.o grade.o median.o Student_info.o
OBJS_5_6_ERASE = problem.5.6_erase.o grade.o median.o Student_info.o
OBJS_MAKE_TEST_FILES = make_test_files.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_5_6_resize test_5_6_erase makeTestFiles

test_5_6_resize : $(OBJS_5_6_RESIZE)
	$(CC) $(LFLAGS) $(OBJS_5_6_RESIZE) -o test_5_6_resize

test_5_6_erase : $(OBJS_5_6_ERASE)
	$(CC) $(LFLAGS) $(OBJS_5_6_ERASE) -o test_5_6_erase

makeTestFiles : $(OBJS_MAKE_TEST_FILES)
	$(CC) $(LFLAGS) $(OBJS_MAKE_TEST_FILES) -o makeTestFiles

make_test_files.o : make_test_files.cpp
	$(CC) $(CFLAGS) make_test_files.cpp

problem.5.6_resize.o : problem.5.6_resize.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.5.6_resize.cpp

problem.5.6_erase.o : problem.5.6_erase.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) problem.5.6_erase.cpp

grade.o : grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

Student_info.o : Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
