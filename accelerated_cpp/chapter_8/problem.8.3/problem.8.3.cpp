#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>

#include <sys/time.h>
#include <ctime>

typedef unsigned long long uint64;

// compare execution time of the first template (uses iterators to avoid copy by value on the container) to second template
// (uses copy by value on a container)  (more apparent for larger containers)
template <class Rand>
auto median(Rand beg, Rand end)
{
  if(beg == end){
    throw std::domain_error("can't calculate median of an empty container");
  }

  sort(beg, end);

  return (end - beg) % 2 == 0 ? 
    (*(beg + (end - beg) / 2) + *(beg - 1 + (end - beg) / 2)) / 2.0 : 
    *(beg + (end - beg) / 2);
}

// compare execution time of the first template (uses iterators to avoid copy by value on the container) to second template
// (uses copy by value on a container)  (more apparent for larger containers)
template <class T>
T median(std::vector<T> v)
{
  typedef typename std::vector<T>::size_type vec_sz;
  vec_sz size = v.size();

  if(size == 0){
    throw std::domain_error("median of an empty vector");
  }

  sort(v.begin(), v.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}




/* Returns the amount of milliseconds elapsed since the UNIX epoch. Works on both
 * windows and linux. */
uint64 GetTimeMs64()
{
 struct timeval tv;

 gettimeofday(&tv, NULL);

 uint64 ret = tv.tv_usec;
 /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
 ret /= 1000;

 /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
 ret += (tv.tv_sec * 1000);

 return ret;
}




int main()
{
  std::vector<double> data;
  std::string s;

  std::cout << "Enter some ints: \n";
  while(std::getline(std::cin, s)){
    data.push_back(std::stoi(s));
  }

  std::cout << "\nSize of dataset: " << data.size() << "\n";
  std::cout << "First number in dataset: " << *data.begin() << "\n";

  uint64 time_begin = GetTimeMs64();
  double median_data = median(data.begin(), data.end());  // use with the template that uses iterators
  //double median_data = median(data);  // use with the template that uses copy by value on the container
  uint64 time_end = GetTimeMs64();

  std::cout << "Execution time: \n" << time_end - time_begin << " milliseconds.\n";
  std::cout << "\nMedian data: " << median_data << std::endl;

  return 0;
}
