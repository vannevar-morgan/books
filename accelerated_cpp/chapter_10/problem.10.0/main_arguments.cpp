/*
 * Example usage of main arguments.
 *
 * Page 179, Section 10.4, Accelerated C++
 */

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "These are the arguments to main:" << std::endl;

  for(int i = 0; i < argc; ++i){
    std::cout << argv[i] << std::endl;
  }
  
  return 0;
}
