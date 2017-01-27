/* $2.e/34
   Problem 2-9
   This program asks the user for 2 numbers and then tells the user which number is larger.
*/

#include <iostream>

int main()
{
  std::cout << "\nEnter 2 numbers separated by a space: ";
  float a;
  float b;
  std::cin >> a;
  std::cin >> b;
  a = (a > b) ? a : b;
  std::cout << "\nThe larger number is " << a << ".\n";

  return 0;
}
