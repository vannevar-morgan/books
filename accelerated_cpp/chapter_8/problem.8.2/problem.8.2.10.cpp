// implements the "remove()" algorithm.
// requires two forward iterators and one variable to compare to.
#include <vector>
#include <iostream>
#include <iterator>
#include <string>


template <class For, class T>
For remove(For beg, For end, T val)
{
  // make a copy of beg to do operations on while retaining original value of beg
  For beg_temp = beg;

  while(beg_temp != end){
    if(*beg_temp != val){
      std::swap(*beg_temp, *beg++); // increment beg so that it points to the next true element.  only do this when a swap occurs.
    }
    ++beg_temp; // increment beg_temp every step through the range [beg, end)
  }

  return beg;
}


int main()
{
  std::cout << "Testing the implementation of the remove() library algorithm...\n" << std::endl;
  int n;
  std::vector<int> nums;


  // get some data from the user to act on
  std::cout << "Enter some integers: \n";
  while(std::cin >> n){
    nums.push_back(n);
  }

  // reset std::cin
  if(!std::cin){
    std::cout << "(press enter)\n";
    std::cin.clear();
    std::string s;
    std::getline(std::cin, s);
  }

  // get a number from the user to remove from the previous data
  std::cout << "Enter an integer to remove from the data: \n";
  std::cin >> n;

  // use remove() to remove the number from the data
  std::vector<int>::const_iterator result;
  result = remove(nums.begin(), nums.end(), n);

  // echo results to user
  std::cout << "This is the data with \"" << n << "\" removed: \n";
  std::vector<int>::const_iterator iter = nums.begin();
  while(iter != result){
    std::cout << *iter++ << "\n";
  }
  std::cout << "***********\n" << *result << "\n";
  iter = result + 1;
  while(iter != nums.end()){
    std::cout << *iter++ << "\n";
  }
  std::cout << "***********\n";
  
  return 0;
}
