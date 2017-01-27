#include "median.hpp"
#include <vector>
#include <stdexcept>
#include <algorithm>

double median(std::vector<double> hw)
{
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = hw.size();

  if(size == 0){
    throw std::domain_error("attempted to take the median of an empty vector...");
  }

  std::sort(hw.begin(), hw.end());
  
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (hw[mid] + hw[mid-1]) / 2 : hw[mid];
}
