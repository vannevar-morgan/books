OBJS_CHAR_PICTURES = char_pictures.o Str.o
OBJS_SPLIT = split.o Str.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : char_pictures split

char_pictures : $(OBJS_CHAR_PICTURES)
	$(CC) $(LFLAGS) $(OBJS_CHAR_PICTURES) -o char_pictures

split : $(OBJS_SPLIT)
	$(CC) $(LFLAGS) $(OBJS_SPLIT) -o split

char_pictures.o : char_pictures.cpp Str.hpp
	$(CC) $(CFLAGS) char_pictures.cpp

split.o : split.cpp Str.hpp
	$(CC) $(CFLAGS) split.cpp

Str.o : Str.cpp Str.hpp
	$(CC) $(CFLAGS) Str.cpp

clean:
	\rm -rf *.o
