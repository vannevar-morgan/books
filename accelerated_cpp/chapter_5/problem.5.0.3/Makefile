OBJS_CP = char_pictures.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_cp

test_cp : $(OBJS_CP)
	$(CC) $(LFLAGS) $(OBJS_CP) -o test_cp

char_pictures.o : char_pictures.cpp
	$(CC) $(CFLAGS) char_pictures.cpp

clean:
	\rm -rf *.o
