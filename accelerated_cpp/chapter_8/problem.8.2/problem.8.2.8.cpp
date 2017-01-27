// implements the "find_if()" algorithm.
// requires two input iterators and a predicate.
#include <vector>
#include <string>
#include <iostream>
#include <iterator>


template <class In, class Pred>
In find_if(In beg, In end, Pred p)
{
  while(beg != end){
    if(p(*beg)){
      return beg;
    }
    ++beg;
  }
  return beg;
}


bool is_negative(int n)
{
  return n < 0;
}


int main()
{
  std::cout << "Testing the implementation of the find_if() library algorithm...\n" << std::endl;
  int n;
  std::vector<int> nums;

  // get some data from the user to act on
  std::cout << "Enter some integers: \n";
  while(std::cin >> n){
    nums.push_back(n);
  }

  // find if any numbers are negative using find_if() and is_negative()
  std::vector<int>::const_iterator result = find_if(nums.begin(), nums.end(), is_negative);

  // echo results to user
  if(result != nums.end()){
    std::cout << "\nDataset contains negative numbers.\n";
    std::vector<int>::const_iterator iter = nums.begin();
    while(iter != result){
      std::cout << *iter++ << "\n";
    }
    std::cout << "***********\n";
    std::cout << *result << "\n";
    std::cout << "***********\n";
    iter = result + 1;
    while(iter != nums.end()){
      std::cout << *iter++ << "\n";
    }
  }else{
    std::cout << "Dataset contains NO negative numbers.\n";
  }
  
  return 0;
}
