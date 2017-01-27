#include "average.h"
#include <vector>  // for vector
#include <numeric>  // for accumulate

double average(const std::vector<double>& v)
{
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
