#include <iostream>


template <class T>
T max(const T& left, const T& right)
{
  return left > right ? left : right;
}

int main()
{
  std::cout << "Enter 2 numbers: " << std::endl;
  double x, y;
  std::cin >> x >> y;
  std::cout << "The larger number is " << max(x, y) << ".\n";
  return 0;
}
