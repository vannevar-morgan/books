// Illustrates why you can't exchange values of iterators directly (they get overwritten) rather than using swap.
// Compare the "partition()" template function to that in to 8.2.11.cpp.
// This one WRONGLY implements the "partition()" algorithm because it exchanges the values of iterators directly rather than using swap.
// Requires two forward iterators and a predicate.
#include <vector>
#include <iostream>
#include <string>


template <class For, class P>
For partition(For beg, For end, P pred)
{
  // make a copy of the "beg" iterator to act on while retaining the original value of beg
  For beg_temp = beg;

  while(beg_temp != end){
    if(pred(*beg_temp)){
      //std::swap(*beg_temp, *beg++); // swap the elements and increment "beg" to point to the next element

      *beg_temp = *beg; // overwrites the value of *beg_temp with the value of *beg
      *beg = *beg_temp; // *beg_temp has already been overwritten with *beg!
      ++beg;

    }
    ++beg_temp; // increment beg_temp through the range [beg, end)
  }
  return beg;
}

bool isNegative(int n)
{
  return n < 0;
}

int main()
{
  std::cout << "Testing (incorrect) partition() using direct exchange of iterator values rather than swap... (values will be overwritten)\n" << std::endl;
  int n;
  std::vector<int> nums;

  // get some data from the user to act on
  std::cout << "Enter some integers (negative ints will be partitioned to the front of the dataset): \n";
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

  // use partition() and isNegative() to partition the data
  std::vector<int>::const_iterator result;
  result = partition(nums.begin(), nums.end(), isNegative);

  //echo result to user
  std::cout << "This is the partitioned data: \n";

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
