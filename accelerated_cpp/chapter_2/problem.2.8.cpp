/*
  $2.e/34
  Problem 2-8
  This program prints the product of the numbers in the range [1, 10)
*/

#include <iostream>

int main()
{
  int a = 1;
  for (int b = 1; b < 10; ++b)
    a *= b;
  
  std::cout << "\n" << a << "\n\n";
  
  return 0;
}
