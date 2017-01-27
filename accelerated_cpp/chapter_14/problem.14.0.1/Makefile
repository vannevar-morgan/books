OBJS_14_0_1 = main.o Core.o Grad.o grading.o median.o ops.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_14_0_1

test_14_0_1 : $(OBJS_14_0_1)
	$(CC) $(LFLAGS) $(OBJS_14_0_1) -o test_14_0_1

main.o : main.cpp Handle.hpp Core.hpp Grad.hpp ops.hpp
	$(CC) $(CFLAGS) main.cpp

Core.o : Core.cpp Core.hpp grading.hpp median.hpp ops.hpp
	$(CC) $(CFLAGS) Core.cpp

Grad.o : Grad.cpp Grad.hpp Core.hpp
	$(CC) $(CFLAGS) Grad.cpp

grading.o : grading.cpp grading.hpp median.hpp
	$(CC) $(CFLAGS) grading.cpp

median.o : median.cpp median.hpp
	$(CC) $(CFLAGS) median.cpp

ops.o : ops.cpp ops.hpp Core.hpp Handle.hpp
	$(CC) $(CFLAGS) ops.cpp


clean:
	\rm -rf *.o *~ grade
