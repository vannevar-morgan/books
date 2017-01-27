// implements the "swap()" function
// requires two variables of the same type
#include <vector>
#include <iostream>
#include <iterator>


template <class T>
void swap(T& x, T&y)
{
  T x_temp = x;
  x = y;
  y = x_temp;
}

int main()
{
  std::cout << "Testing swap() function...\n" << std::endl;
  int n;
  std::vector<int> nums;

  // get some data from the user to act on
  std::cout << "Enter at least two different integers: \n";
  while(std::cin >> n){
    nums.push_back(n);
  }

  // swap the first two entries
  if(nums.size() > 1){
    swap(*nums.begin(), *(nums.begin() + 1));
  }else{
    std::cout << "You need to enter at least TWO (2) different integers.\n";
    return 0;
  }

  // echo results to user
  std::cout << "This is the data after swapping the first two numbers: \n";
  std::vector<int>::const_iterator iter = nums.begin();
  while(iter != nums.end()){
    std::cout << *iter++ << "\n";
  }
  
  
  return 0;
}
