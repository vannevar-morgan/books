#include "Grad.hpp"
#include "ops.hpp"
#include <istream>
#include <algorithm>


std::istream& Grad::read(std::istream& is)
{
  read_common(is);
  is >> thesis;
  read_hw(is, homework);
  
  return is;
}


double Grad::grade() const
{
  return std::min(thesis, Core::grade());
}
