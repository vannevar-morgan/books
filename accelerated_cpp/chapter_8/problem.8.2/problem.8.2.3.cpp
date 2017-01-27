// implements the "copy()" algorithm.
// requires two input iterators, one output iterator.

#include <vector>
#include <string>
#include <iterator>
#include <iostream>


template <class In, class Out>
Out copy(In beg, In end, Out dest)
{
  while(beg != end){
    *dest++ = *beg++;
  }
  return dest;
}


int main()
{
  std::cout << "Testing the implementation of the copy() library algorithm...\n" << std::endl;
  std::vector<std::string> words;  

  // get some data to act on
  std::cout << "Enter some text: \n";
  std::string s;
  while(std::cin >> s){
    words.push_back(s);
  }

  // copy the text to a second vector
  std::vector<std::string> second_words;
  ::copy(words.begin(), words.end(), std::back_inserter(second_words));

  // echo the text back, using the second vector
  std::cout << "This is the data in the copied vector: \n";
  std::vector<std::string>::const_iterator iter = second_words.begin();
  while(iter != second_words.end()){
    std::cout << *iter++ << "\n";
  }

  return 0;
}
