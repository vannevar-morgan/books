OBJS_16_0 = main.o Ptr.o Str.o Picture.o Core.o Grad.o Student_info.o grading.o median.o ops.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : ztest_16_0

ztest_16_0 : $(OBJS_16_0)
	$(CC) $(LFLAGS) $(OBJS_16_0) -o ztest_16_0

Ptr.o : Ptr.cpp Ptr.hpp RefCount.hpp Vec.hpp
	$(CC) $(CFLAGS) Ptr.cpp

Str.o : Str.cpp Str.hpp Vec.hpp Ptr.hpp
	$(CC) $(CFLAGS) Str.cpp

Picture.o : Picture.cpp Picture.hpp Ptr.hpp RefCount.hpp Vec.hpp Str.hpp
	$(CC) $(CFLAGS) Picture.cpp

Core.o : Core.cpp Core.hpp grading.hpp median.hpp ops.hpp Vec.hpp Str.hpp
	$(CC) $(CFLAGS) Core.cpp

Grad.o : Grad.cpp Grad.hpp Core.hpp
	$(CC) $(CFLAGS) Grad.cpp

Student_info.o : Student_info.cpp Student_info.hpp Core.hpp Str.hpp
	$(CC) $(CFLAGS) Student_info.cpp

grading.o : grading.cpp grading.hpp median.hpp Vec.hpp
	$(CC) $(CFLAGS) grading.cpp

median.o : median.cpp median.hpp Vec.hpp
	$(CC) $(CFLAGS) median.cpp

ops.o : ops.cpp ops.hpp Vec.hpp
	$(CC) $(CFLAGS) ops.cpp

main.o : main.cpp Picture.hpp Ptr.hpp RefCount.hpp Vec.hpp Str.hpp Student_info.hpp
	$(CC) $(CFLAGS) main.cpp


clean:
	\rm -rf *.o
