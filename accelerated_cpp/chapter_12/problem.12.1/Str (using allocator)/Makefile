OBJS = test_Str.o Str.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_Str

test_Str : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test_Str

test_Str.o : test_Str.cpp Str.hpp
	$(CC) $(CFLAGS) test_Str.cpp

Str.o : Str.cpp Str.hpp
	$(CC) $(CFLAGS) Str.cpp

clean:
	\rm -rf *.o
