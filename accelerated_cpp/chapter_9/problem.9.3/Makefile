OBJS = grading_with_exception.o Student_info.o
OBJS_SAFE = grading_catching_exception.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : grade_students grade_students_safe

grade_students : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o grade_students

grade_students_safe : $(OBJS_SAFE)
	$(CC) $(LFLAGS) $(OBJS_SAFE) -o grade_students_safe

grading_with_exception.o : grading_with_exception.cpp Student_info.hpp
	$(CC) $(CFLAGS) grading_with_exception.cpp

grading_catching_exception.o : grading_catching_exception.cpp Student_info.hpp
	$(CC) $(CFLAGS) grading_catching_exception.cpp

Student_info.o : Student_info.cpp Student_info.hpp
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
