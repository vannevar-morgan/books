OBJS_14_3 = main.o Core.o Grad.o grading.o median.o ops.o Student_info.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_14_3

test_14_3 : $(OBJS_14_3)
	$(CC) $(LFLAGS) $(OBJS_14_3) -o test_14_3

main.o : main.cpp Student_info.hpp
	$(CC) $(CFLAGS) main.cpp

Core.o : Core.cpp Core.hpp grading.hpp median.hpp ops.hpp
	$(CC) $(CFLAGS) Core.cpp

Grad.o : Grad.cpp Grad.hpp Core.hpp
	$(CC) $(CFLAGS) Grad.cpp

grading.o : grading.cpp grading.hpp median.hpp
	$(CC) $(CFLAGS) grading.cpp

median.o : median.cpp median.hpp
	$(CC) $(CFLAGS) median.cpp

ops.o : ops.cpp ops.hpp
	$(CC) $(CFLAGS) ops.cpp

Student_info.o : Student_info.cpp Student_info.hpp Core.hpp Grad.hpp Ptr.hpp
	$(CC) $(CFLAGS) Student_info.cpp


clean:
	\rm -rf *.o *~ grade
