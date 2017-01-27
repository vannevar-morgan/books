OBJS_10_6 = problem.10.6.o
OBJS_VERIFY_LIST = verify_list.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_10_6 verify_list

test_10_6 : $(OBJS_10_6)
	$(CC) $(LFLAGS) $(OBJS_10_6) -o test_10_6

verify_list : $(OBJS_VERIFY_LIST)
	$(CC) $(LFLAGS) $(OBJS_VERIFY_LIST) -o verify_list

problem.10.6.o : problem.10.6.cpp List.hpp ListIterator.hpp ListNode.hpp
	$(CC) $(CFLAGS) problem.10.6.cpp

verify_list.o : verify_list.cpp List.hpp ListIterator.hpp ListNode.hpp
	$(CC) $(CFLAGS) verify_list.cpp

clean:
	\rm -rf *.o
