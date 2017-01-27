OBJS_CP = char_pictures.o
OBJS_9_0 = problem.9.0.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_cp test_9_0

test_cp : $(OBJS_CP)
	$(CC) $(LFLAGS) $(OBJS_CP) -o test_cp

test_9_0 : $(OBJS_9_0)
	$(CC) $(LFLAGS) $(OBJS_9_0) -o test_9_0

char_pictures.o : char_pictures.cpp Vec.hpp
	$(CC) $(CFLAGS) char_pictures.cpp

problem.9.0.o : problem.9.0.cpp Vec.hpp Student_info.hpp
	$(CC) $(CFLAGS) problem.9.0.cpp

Student_info.o : Student_info.cpp Student_info.hpp
	$(CC) $(CFLAGS) Student_info.cpp

clean:
	\rm -rf *.o
