OBJS_URLS = problem.6.0.3.o urls.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : urls

urls : $(OBJS_URLS)
	$(CC) $(LFLAGS) $(OBJS_URLS) -o urls

problem.6.0.3.o : problem.6.0.3.cpp urls.hpp
	$(CC) $(CFLAGS) problem.6.0.3.cpp

urls.o : urls.cpp urls.hpp
	$(CC) $(CFLAGS) urls.cpp

clean:
	\rm -rf *.o
