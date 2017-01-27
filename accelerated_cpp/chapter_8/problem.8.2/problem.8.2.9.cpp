// implements the "remove_copy()" algorithm.
// requires two input iterators, one output iterator, and a value t to compare against elements to keep.
#include <vector>
#include <iostream>
#include <string>
#include <iterator>


template <class In, class Out, class T>
Out remove_copy(In beg, In end, Out dest, T val)
{
  while(beg != end){
    if(*beg != val){
      *dest++ = *beg;
    }
    ++beg;
  }
  return dest;  
}



int main()
{
  std::cout << "Testing the implementation of the remove_copy() library algorithm...\n" << std::endl;
  std::vector<std::string> words;
  std::string s;

  // get some data from the user to test on
  std::cout << "Enter some words: \n";
  while(std::cin >> s){
    words.push_back(s);
  }
  
  //reset std::cin
  if(!std::cin){
    std::cout << "(press enter)\n";
    std::cin.clear();
    std::getline(std::cin, s);
  }
  
  // get a string to remove from the collection of words
  std::cout << "Enter a word to remove from the first set: \n";
  std::cin >> s;
  
  // use remove_copy() to get the collection of words that aren't "cat"
  std::vector<std::string> words2;
  remove_copy(words.begin(), words.end(), back_inserter(words2), s);
  
  // echo results to the user
  std::cout << "These are the previous words excluding \"" << s << "\": \n";
  std::vector<std::string>::const_iterator iter = words2.begin();
  std::cout << *iter++;
  while(iter != words2.end()){
    std::cout << " " << *iter++;
  }
  std::cout << "\n";
  
  return 0;
}
