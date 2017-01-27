#include <iostream>
#include <string>

int main()
{
  { const std::string s = "a string";
    std::cout << s << std::endl; }

  { const std::string s = "another string";
    std::cout << s << std::endl; }

  return 0;
}

//
// Prints:
// "a string"
// "another string"
//
// Valid because each string, s, is defined in it's own scope.
//
