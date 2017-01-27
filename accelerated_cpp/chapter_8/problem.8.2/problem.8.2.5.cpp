// implements the "transform()" algorithm.
// requires two input iterators, one output iterator, and a function to apply over the range.

#include <iostream>
#include <vector>
#include <string>
#include <iterator>


template <class In, class Out, class Function>
Out transform(In beg, In end, Out dest, Function f)
{
  while(beg != end){
    *dest++ = f(*beg++);
  }
  return dest;
}

int square(int n)
{
  return n*n;
}

int less_one(int n)
{
  return n - 1;
}

int main()
{
  std::cout << "Testing the implementation of the transform() library algorithm...\n" << std::endl;
  int n;
  std::vector<int> nums;
  
  // get some data to test the template on
  std::cout << "Enter some integers: \n";
  while(std::cin >> n){
    nums.push_back(n);
  }

  // reset std::cin
  if(!std::cin){
    std::cout << "(press enter)\n";
    std::string s;
    std::cin.clear();
    std::getline(std::cin, s);
  }

  // call transform() to apply the square function to the data
  std::vector<int> nums2;
  ::transform(nums.begin(), nums.end(), back_inserter(nums2), square);

  // call transform again to demonstrate calling with a different function
  nums.erase(nums.begin(), nums.end());
  ::transform(nums2.begin(), nums2.end(), back_inserter(nums), less_one);

  // echo results
  std::cout << "These are the squares (minus one): \n";
  std::vector<int>::const_iterator iter = nums.begin();
  while(iter != nums.end()){
    std::cout << *iter++ << "\n";
  }



  return 0;
}
