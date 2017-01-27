OBJS_7_5 = problem.7.5.o gen_sentence.o grammar.o nrand.o parsing.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_7_5

test_7_5 : $(OBJS_7_5)
	$(CC) $(LFLAGS) $(OBJS_7_5) -o test_7_5

problem.7.5.o : problem.7.5.cpp gen_sentence.h grammar.h parsing.h nrand.h
	$(CC) $(CFLAGS) problem.7.5.cpp

gen_sentence.o : gen_sentence.cpp grammar.h parsing.h nrand.h gen_sentence.h
	$(CC) $(CFLAGS) gen_sentence.cpp

grammar.o : grammar.cpp parsing.h grammar.h
	$(CC) $(CFLAGS) grammar.cpp

nrand.o : nrand.cpp nrand.h
	$(CC) $(CFLAGS) nrand.cpp

parsing.o : parsing.cpp parsing.h
	$(CC) $(CFLAGS) parsing.cpp

clean:
	\rm -rf *.o
