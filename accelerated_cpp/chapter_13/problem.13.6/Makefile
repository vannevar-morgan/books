OBJS = main.o Core.o Grad.o PassFailStudent.o Student_info.o grading.o median.o ops.o
CC = g++
CFLAGS = -c -Wall -g
LFLAGS = -Wall

grade : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o grade

main.o : main.cpp Student_info.hpp Core.hpp Grad.hpp
	$(CC) $(CFLAGS) main.cpp

Core.o : Core.cpp Core.hpp grading.hpp median.hpp ops.hpp
	$(CC) $(CFLAGS) Core.cpp

Grad.o : Grad.cpp Grad.hpp Core.hpp
	$(CC) $(CFLAGS) Grad.cpp

PassFailStudent.o : PassFailStudent.cpp PassFailStudent.hpp Core.hpp
	$(CC) $(CFLAGS) PassFailStudent.cpp

Student_info.o : Student_info.cpp Student_info.hpp Core.hpp
	$(CC) $(CFLAGS) Student_info.cpp

grading.o : grading.cpp grading.hpp median.hpp
	$(CC) $(CFLAGS) grading.cpp

median.o : median.cpp median.hpp
	$(CC) $(CFLAGS) median.cpp

ops.o : ops.cpp ops.hpp
	$(CC) $(CFLAGS) ops.cpp


clean:
	\rm -rf *.o *~ grade
