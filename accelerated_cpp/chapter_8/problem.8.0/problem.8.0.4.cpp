#include <iostream>
#include <vector>
#include <iterator>


template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
  while(begin != end){
    *dest++ = *begin++;
  }
  return dest;
}


int main()
{
  std::vector<int> numbers;
  std::cout << "Enter some integers: " << std::endl;
  int s;
  while(std::cin >> s){
    numbers.push_back(s);
  }

  std::vector<int> second_numbers;
  ::copy(numbers.begin(), numbers.end(), back_inserter(second_numbers));
  
  std::cout << "These are the (copied) numbers you entered: " << std::endl;
  std::vector<int>::const_iterator iter;
  for(iter = second_numbers.begin(); iter != second_numbers.end(); ++iter){
    std::cout << *iter << std::endl;
  }

  return 0;
}
