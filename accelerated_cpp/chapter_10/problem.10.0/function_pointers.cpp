/*
 * Illustrates function pointers and use of ptrdiff_t from the <cstddef> header
 *
 */

#include <iostream>
#include <vector>
#include <cstddef> // for ptrdiff_t

double calc_average(double a, double b);

template <class in, class pred>
in find_if(in begin, in end, pred f)
{
  while(begin != end && !f(*begin)){
    ++begin;
  }
  return begin;
}

bool is_negative(int n)
{
  return n < 0;
}

int main()
{
  double (*fp)(double, double) = calc_average; // creates a function pointer, fp, pointing to calc_average

  std::cout << (*fp)(5, 15) << std::endl;

  std::cout << "enter some numbers to look for a negative number: \n";
  std::vector<double> nums;
  double n;
  while(std::cin >> n){
    nums.push_back(n);
  }

  std::vector<double>::iterator i = find_if(nums.begin(), nums.end(), is_negative);
  if(i != nums.end()){
    ptrdiff_t index = i - nums.begin();
    std::cout << "first negative number: " << *i << std::endl;
    std::cout << "index in vector: " << index << std::endl;
  }

  return 0;
}

double calc_average(double a, double b)
{
  return (a + b) / 2;
}

