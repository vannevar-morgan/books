#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
  std::vector<int> u(10, 100);
  std::vector<int>::const_iterator i = u.begin();
  std::vector<int>::const_iterator j = u.end();

  std::cout << "This is the original data..." << std::endl;
  while (i != j) {
    std::cout << *i << std::endl;
    ++i;
  }

  std::vector<int> v;
  // problem.6.3, can't use v.begin() to copy into because v has no elements or memory allocated.  need to use std::back_inserter.
  copy(u.begin(), u.end(), v.begin());
  //
  // problem.6.4, use std::back_inserter to get an iterator to copy data to.
  // copy(u.begin(), u.end(), std::back_inserter(v));
  //
  // problem.6.4, alternatively if we allocate space in the vector for all elements to be copied then we can use v.begin() as the destination iterator for std::copy()
  // std::vector<int> v(u.size());
  // copy(u.begin(), u.end(), v.begin());
  
  std::vector<int>::const_iterator a = v.begin();
  std::vector<int>::const_iterator b = v.end();
  
  std::cout << "\nThis is the copied data..." << std::endl;
  while (a != b) {
    std::cout << *a << std::endl;
    ++a;
  }


  return 0;
}
