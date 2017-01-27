#include "Grad.hpp"
#include "ops.hpp"
#include <istream>
#include <algorithm>
#include <iostream>

std::istream& Grad::read(std::istream& is)
{
  read_common(is);
  is >> thesis;
  read_hw(is, homework);
  
  return is;
}


double Grad::grade() const
{
  std::cout << "Grad::grade()" << std::endl;
  return std::min(thesis, Core::grade());
}
