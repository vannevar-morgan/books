/*
  $2.e/34
  Problem 2-7
  This program prints each number in the range [10, -6) on a new line.
*/

#include <iostream>

int main()
{
  // Using a for loop
  std::cout << "\n\n";
  for (int i = 10; i != -6; i--)
    std::cout << i << "\n";

  std::cout << "\n";

  // Using a while loop
  int i = 10;
  while (i != -6){
    std::cout << i << "\n";
    --i;
  }

  return 0;
}
