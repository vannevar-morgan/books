/*
 * Example usage of pointers to find the length of a string.
 * 
 * Page 177, Section 10.2, Accelerated C++
 */

#include <iostream>
#include <cstddef>
#include <string>

size_t strlen(const char* p);

int main()
{
  std::string s = "";
  std::cout << "Enter a string to get the length of: ";
  std::cin >> s;

  std::cout << "string is: " << s << std::endl;
  std::cout << "string length is " << strlen(s.c_str()) << std::endl;

  return 0;
}

size_t strlen(const char* p)
{
  size_t s = 0;
  while(*p++ != '\0'){
    ++s;
  }
  return s;
}
