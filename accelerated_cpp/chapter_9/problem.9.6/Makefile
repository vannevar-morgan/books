OBJS = grade_students_pf.o Student_info_pf.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : grade_students

grade_students : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o grade_students

grade_students_pf.o : grade_students_pf.cpp Student_info_pf.hpp
	$(CC) $(CFLAGS) grade_students_pf.cpp

Student_info_pf.o : Student_info_pf.cpp Student_info_pf.hpp
	$(CC) $(CFLAGS) Student_info_pf.cpp

clean:
	\rm -rf *.o
