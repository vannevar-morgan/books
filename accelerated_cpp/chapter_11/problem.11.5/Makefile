OBJS_GRADE = grade_students.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_grade_students

test_grade_students : $(OBJS_GRADE)
	$(CC) $(LFLAGS) $(OBJS_GRADE) -o test_grade_students

grade_students.o : grade_students.cpp Student_info.hpp
	$(CC) $(CFLAGS) grade_students.cpp

Student_info.o : Student_info.cpp Student_info.hpp
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
