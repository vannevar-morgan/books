OBJS_BASIC_POINTERS = basic_pointers.o
OBJS_DUPLICATE_CHARS = duplicate_chars.o
OBJS_FUNCTION_POINTERS = function_pointers.o
OBJS_LETTER_GRADE = letter_grade.o
OBJS_MAIN_ARGUMENTS = main_arguments.o
OBJS_STATIC_AND_DYNAMIC_POINTERS = static_and_dynamic_pointers.o
OBJS_STRING_LENGTH = string_length.o
OBJS_FILE_COPY = file_copy.o
OBJS_FILE_PRINT = file_print.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : test_basic_pointers test_duplicate_chars test_function_pointers test_letter_grade test_main_arguments test_static_and_dynamic_pointers test_string_length test_file_copy test_file_print

test_basic_pointers : $(OBJS_BASIC_POINTERS)
	$(CC) $(LFLAGS) $(OBJS_BASIC_POINTERS) -o test_basic_pointers

test_duplicate_chars : $(OBJS_DUPLICATE_CHARS)
	$(CC) $(LFLAGS) $(OBJS_DUPLICATE_CHARS) -o test_duplicate_chars

test_function_pointers : $(OBJS_FUNCTION_POINTERS)
	$(CC) $(LFLAGS) $(OBJS_FUNCTION_POINTERS) -o test_function_pointers

test_letter_grade : $(OBJS_LETTER_GRADE)
	$(CC) $(LFLAGS) $(OBJS_LETTER_GRADE) -o test_letter_grade

test_main_arguments : $(OBJS_MAIN_ARGUMENTS)
	$(CC) $(LFLAGS) $(OBJS_MAIN_ARGUMENTS) -o test_main_arguments

test_static_and_dynamic_pointers : $(OBJS_STATIC_AND_DYNAMIC_POINTERS)
	$(CC) $(LFLAGS) $(OBJS_STATIC_AND_DYNAMIC_POINTERS) -o test_static_and_dynamic_pointers

test_string_length : $(OBJS_STRING_LENGTH)
	$(CC) $(LFLAGS) $(OBJS_STRING_LENGTH) -o test_string_length

test_file_copy : $(OBJS_FILE_COPY)
	$(CC) $(LFLAGS) $(OBJS_FILE_COPY) -o ./file_copy/test_file_copy

test_file_print : $(OBJS_FILE_PRINT)
	$(CC) $(LFLAGS) $(OBJS_FILE_PRINT) -o ./file_print/test_file_print

basic_pointers.o : basic_pointers.cpp
	$(CC) $(CFLAGS) basic_pointers.cpp

duplicate_chars.o : duplicate_chars.cpp
	$(CC) $(CFLAGS) duplicate_chars.cpp

function_pointers.o : function_pointers.cpp
	$(CC) $(CFLAGS) function_pointers.cpp

letter_grade.o : letter_grade.cpp
	$(CC) $(CFLAGS) letter_grade.cpp

main_arguments.o : main_arguments.cpp
	$(CC) $(CFLAGS) main_arguments.cpp

static_and_dynamic_pointers.o : static_and_dynamic_pointers.cpp
	$(CC) $(CFLAGS) static_and_dynamic_pointers.cpp

string_length.o : string_length.cpp
	$(CC) $(CFLAGS) string_length.cpp

# file_copy has the potential to overwrite files (it will write to whatever file you provide as an output file).  so you should run it from the file_copy folder to minimize the potential for accidentally overwriting a file.
file_copy.o : ./file_copy/file_copy.cpp
	$(CC) $(CFLAGS) ./file_copy/file_copy.cpp

file_print.o : ./file_print/file_print.cpp
	$(CC) $(CFLAGS) ./file_print/file_print.cpp

clean:
	\rm -rf *.o
