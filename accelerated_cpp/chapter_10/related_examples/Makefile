OBJS_EX = malloc_example.o
OBJS_EX_2 = malloc_example2.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_ex test_ex_2

test_ex : $(OBJS_EX)
	$(CC) $(LFLAGS) $(OBJS_EX) -o test_ex

test_ex_2 : $(OBJS_EX_2)
	$(CC) $(LFLAGS) $(OBJS_EX_2) -o test_ex_2

malloc_example.o : malloc_example.cpp
	$(CC) $(CFLAGS) malloc_example.cpp

malloc_example2.o : malloc_example2.cpp
	$(CC) $(CFLAGS) malloc_example2.cpp

clean:
	\rm -rf *.o
