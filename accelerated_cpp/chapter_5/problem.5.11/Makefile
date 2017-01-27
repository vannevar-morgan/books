OBJS_ASC_DESC = problem.5.11.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : asc_desc

asc_desc : $(OBJS_ASC_DESC)
	$(CC) $(LFLAGS) $(OBJS_ASC_DESC) -o asc_desc

problem.5.11.o : problem.5.11.cpp
	$(CC) $(CFLAGS) problem.5.11.cpp

clean:
	\rm -rf *.o
