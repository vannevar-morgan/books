//#include <vector>
#include <stdexcept>
#include <algorithm>
#include "median.hpp"
#include "Vec.hpp"


double median(Vec<double> hw)
{
  typedef Vec<double>::size_type vec_sz;
  vec_sz size = hw.size();

  if(size == 0){
    throw std::domain_error("attempted to take the median of an empty Vec...");
  }

  std::sort(hw.begin(), hw.end());
  
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (hw[mid] + hw[mid-1]) / 2 : hw[mid];
}
