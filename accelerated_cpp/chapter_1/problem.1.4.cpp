#include <iostream>
#include <string>

int main()
{
  { const std::string s = "a string";
    std::cout << s << std::endl;

    { const std::string s = "another string";
      std::cout << s << std::endl; }}

  return 0;
}


//
// Prints:
// "a string"
// "another string"
//
// Valid because the second variable s = "another string" exists in a 
// different scope than the first variable s = "a string" variable.
//
// So it doesn't conflict to define a new variable s in this scope 
// when s is already defined in a lower nested scope.
// 
// The second variable s shadows the first variable s which is why this
// program prints:
// "a string"
// "another string"
//
// instead of:
// "a string"
// "a string"
//

