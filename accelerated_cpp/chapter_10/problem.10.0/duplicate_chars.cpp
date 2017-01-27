/*
 * Example of pointer usage and dynamic memory management.  Function takes a 
 * character pointer, calculates required space to copy the string, allocates 
 * space, copies the string, returns a dynamic pointer to the string.
 *
 * Shows use of sizeof() to determine the size of an array.
 *
 * Page 185, Section 10.7, Accelerated C++
 */

#include <cstddef> // for size_t
#include <cstring> // for strlen()
#include <algorithm> // for copy()
#include <iostream>

char* duplicate_chars(const char* p);

int main()
{
  // call duplicate_chars() with a string literal
  char* p = duplicate_chars("tbilisi");
  char* q = p; // make a copy of p to increment so that the memory pointed to by p can be later freed

  // print copied chars to string
  while(*q != '\0'){
    std::cout << *q++;
  }
  std::cout << std::endl;

  delete[] p;
  return 0;
}

char* duplicate_chars(const char* p)
{
  //
  // Takes a const char*, copies data to new char[], returns pointer to char.
  //

  // get size of the string literal
  size_t array_size = strlen(p) + 1; // add one for the null character

  // allocate space to copy string
  char* copied_chars = new char[array_size];

  // copy string
  std::copy(p, p + array_size, copied_chars);

  return copied_chars;
}
