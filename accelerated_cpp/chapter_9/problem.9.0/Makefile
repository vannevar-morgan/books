OBJS = grade_students.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : grade_students

grade_students : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o grade_students

grade_students.o : grade_students.cpp Student_info.hpp
	$(CC) $(CFLAGS) grade_students.cpp

Student_info.o : Student_info.cpp Student_info.hpp
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
