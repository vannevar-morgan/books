// implements "accumulate()" (defined in <numeric>).
// requires two input iterators and a variable to initialize a copy from.

#include <vector>
#include <iostream>


template <class In, class X>
X accumulate(In beg, In end, X x)
{
  while(beg != end){
    x += *beg++;
  }
  return x;
}

int main()
{
  std::cout << "Testing the implementation of the accumulate() library algorithm...\n" << std::endl;
  int n;
  std::vector<int> data;

  //get data from user
  std::cout << "Enter some integers: \n";
  while(std::cin >> n){
    data.push_back(n);
  }

  // use accumulate to get the sum of the numbers in data
  int a = 0;
  a = accumulate(data.begin(), data.end(), a);

  // echo results to user
  std::cout << "This is what those numbers sum to: \t" << a << "\n";

  return 0;
}
