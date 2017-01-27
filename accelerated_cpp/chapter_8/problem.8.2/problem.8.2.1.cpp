// this is an implementation of the "equal()" library algorithm.
// requires 3 input iterators.

#include <vector>
#include <iostream>
#include <string>


template <class In>
bool equal(In beg, In end, In beg2)
{
  while(beg != end && *beg == *beg2){
    ++beg;
    ++beg2;
  }
  if(beg != end){
    return false;
  }else{
    return true;
  }
}

int main()
{
  std::cout << "Testing the implementation of the equal() library algorithm...\n" << std::endl;
  std::vector<int> numbers_set1;
  std::vector<int> numbers_set2;

  // read in the first list of numbers
  std::cout << "Enter the first set of integers: \n";
  int n;
  while(std::cin >> n){
    numbers_set1.push_back(n);
  }

  // reset std::cin
  std::cout << "(press enter)\n";
  if(!std::cin){
    std::cin.clear();
    std::string s;
    std::getline(std::cin, s);
  }
  
  // read in the second set of numbers
  std::cout << "Enter the second set of integers: \n";
  while(std::cin >> n){
    numbers_set2.push_back(n);
  }

  // call the equal function to see if the sequences of numbers are equal
  bool nums_are_equal = equal(numbers_set1.begin(), numbers_set1.end(), numbers_set2.begin());
  if(nums_are_equal){
    std::cout << "The sequences are equal.\n";
  }else{
    std::cout << "The sequences are NOT equal.\n";
  }

  return 0;
}
