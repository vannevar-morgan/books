#include <iostream>
#include <string>

int main(){
  // Valid because concatenation is left-associative.
  const std::string hello = "hello";
  const std::string message = hello + ", world" + "!";

  std::cout << hello << std::endl;
  std::cout << message << std::endl;
  
  return 0;
}
