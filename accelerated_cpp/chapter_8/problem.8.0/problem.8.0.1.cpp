#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>


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


int main()
{
  std::vector<double> nums;

  int temp_num;
  std::cout << "Enter some ints: " << std::endl;
  while(std::cin >> temp_num){
    nums.push_back(temp_num);
  }
  double median_num = median(nums);
  std::cout << "\nMedian num: " << median_num << std::endl;
  
  return 0;
}
