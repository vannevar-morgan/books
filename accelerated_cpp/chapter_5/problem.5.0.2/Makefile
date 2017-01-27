OBJS_SS = split_string.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_ss

test_ss : $(OBJS_SS)
	$(CC) $(LFLAGS) $(OBJS_SS) -o test_ss

split_string.o : split_string.cpp
	$(CC) $(CFLAGS) split_string.cpp

clean:
	\rm -rf *.o
