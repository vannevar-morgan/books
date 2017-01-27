OBJS = grading_with_valid.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : grade_students

grade_students : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o grade_students

grading_with_valid.o : grading_with_valid.cpp Student_info.hpp
	$(CC) $(CFLAGS) grading_with_valid.cpp

Student_info.o : Student_info.cpp Student_info.hpp
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
