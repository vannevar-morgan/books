// implements the "remove_copy_if()" algorithm.
// requires two input iterators, one output iterator, and a predicate.

#include <vector>
#include <iostream>
#include <string>
#include <iterator>


template <class In, class Out, class Pred>
Out remove_copy_if(In beg, In end, Out dest, Pred test)
{
  while(beg != end){
    if(!test(*beg)){
      *dest++ = *beg;
    }
    ++beg;
  }

  return dest;
}

bool not_freezing(int temp)
{
  return temp > 32;
}

int main()
{
  std::cout << "Testing the implementation of the remove_copy_if() library algorithm...\n" << std::endl;
  int n;
  std::vector<int> data;

  // get some numbers to test on
  std::cout << "Enter some fahrenheit temperatures: \n";
  while(std::cin >> n){
    data.push_back(n);
  }

  // reset std::cin
  std::cout << "(press enter)\n";
  if(!std::cin){
    std::cin.clear();
    std::string s;
    std::getline(std::cin, s);
  }

  // use remove_copy_if() to get the set of all elements which fail the predicate
  std::vector<int> data_freeze;
  remove_copy_if(data.begin(), data.end(), std::back_inserter(data_freeze), not_freezing);

  // echo results
  std::cout << "Water will freeze for these temperatures: \n";
  std::vector<int>::const_iterator iter = data_freeze.begin();
  while(iter != data_freeze.end()){
    std::cout << *iter++ << "\n";
  }
  
  return 0;
}
