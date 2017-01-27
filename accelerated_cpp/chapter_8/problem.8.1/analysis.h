#ifndef analysis_h
#define analysis_h

#include "median.h"  // for median()
#include <vector>  // for vector
#include <algorithm>  // for transform()
#include <iterator>  // for back_inserter()
#include <ostream>  // for ostream
#include <string>  // for string


template <class In, class F>
double analysis(In beg, In end, F zFunc)
{
  std::vector<double> grades;
  transform(beg, end, back_inserter(grades), zFunc);
  return median(grades);
}

#endif
