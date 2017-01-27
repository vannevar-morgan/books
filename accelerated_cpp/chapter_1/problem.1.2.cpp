#include <iostream>
#include <string>

int main(){
  // The second definition is wrong because it first attempts to concatenate two
  // string literals due to left association, which the '+' operator can't do.
  const std::string exclam = "!";
  const std::string message = "hello" + ", world" + exclam;
  
  std::cout << exclam << std::endl;
  std::cout << message << std::endl;
  
  return 0;
}
