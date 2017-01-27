
#include "median.hpp"
#include <vector>
#include <iostream>
#include <cstddef> // for size_t

int main()
{
  double nums1[] = {100.0, 200.0, 300.0, 400.0, 500.0, 600.0, 700.0, 800.0, 900.0, 2500.0}; // median should be 550.0
  size_t nums1_sz = sizeof(nums1) / sizeof(*nums1);

  double nums2[] = {100.0, 200.0, 300.0, 400.0, 500.0, 600.0, 700.0, 800.0, 2500.0}; // median should be 500.0
  size_t nums2_sz = sizeof(nums2) / sizeof(*nums2);

  std::cout << "Testing median function with vectors and arrays...\n" << std::endl;
  std::cout << "(data for first two arrays of type double is already defined)...\n";

  // get data for nums 3
  std::vector<double> nums3;
  std::cout << "Enter some numbers to test the median function with a vector:" << std::endl;
  double n;
  while(std::cin >> n){
    nums3.push_back(n);
  }

  // calculate medians
  double m1 = median<double>(nums1, nums1 + nums1_sz);
  double m2 = median<double>(nums2, nums2 + nums2_sz);
  double m3 = median<double>(nums3.begin(), nums3.end());

  // print out medians
  std::cout << std::endl;
  std::cout << "median of nums1: " << m1 << std::endl;
  std::cout << "median of nums2: " << m2 << std::endl;
  std::cout << "median of nums3: " << m3 << std::endl;
  std::cout << std::endl;

  // print out data to verify the order of data wasn't changed
  std::cout << "This is the data you entered (verify it isn't changed by the median function):" << std::endl;
  for(std::vector<double>::size_type i = 0; i != nums3.size(); ++i){
    std::cout << nums3[i] << " ";
  }
  std::cout << std::endl;
}
