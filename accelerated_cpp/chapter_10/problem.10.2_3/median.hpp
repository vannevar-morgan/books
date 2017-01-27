#ifndef GUARD_median_h
#define GUARD_median_h

#include <stdexcept> // for std::domain_error
#include <algorithm> // for std::sort
#include <vector>

template <class T, class iterator>
T median(iterator begin, iterator end)
{
  if(begin == end){
    throw std::domain_error("attempted to calculate the median of an empty data structure...");
  }

  // copy data before sorting to avoid changing original data
  std::vector<T> data;
  while(begin < end){
    data.push_back(*begin++);
  }
  
  // sort the data before calculating the middle element
  std::sort(data.begin(), data.end());
  
  typename std::vector<T>::size_type mid = data.size() / 2;

  if(data.size() % 2 == 1){
    return data[mid];
  }else{
    return (data[mid] + data[mid - 1]) / 2;
  }
  
}



#endif
