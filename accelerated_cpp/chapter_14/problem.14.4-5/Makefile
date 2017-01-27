OBJS_TEST_STR = Ptr.o Str.o test_Str.o
OBJS_CHAR_PICTURES = char_pictures.o Ptr.o Str.o
OBJS_SPLIT = split.o Ptr.o Str.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_Str char_pictures split

test_Str : $(OBJS_TEST_STR)
	$(CC) $(LFLAGS) $(OBJS_TEST_STR) -o test_Str

char_pictures : $(OBJS_CHAR_PICTURES)
	$(CC) $(LFLAGS) $(OBJS_CHAR_PICTURES) -o char_pictures

split : $(OBJS_SPLIT)
	$(CC) $(LFLAGS) $(OBJS_SPLIT) -o split

Ptr.o : Ptr.cpp Ptr.hpp
	$(CC) $(CFLAGS) Ptr.cpp

Str.o : Str.cpp Str.hpp Vec.hpp Ptr.hpp
	$(CC) $(CFLAGS) Str.cpp

test_Str.o : test_Str.cpp Str.hpp Vec.hpp
	$(CC) $(CFLAGS) test_Str.cpp

char_pictures.o : char_pictures.cpp Str.hpp
	$(CC) $(CFLAGS) char_pictures.cpp

split.o : split.cpp Str.hpp
	$(CC) $(CFLAGS) split.cpp


clean:
	\rm -rf *.o
