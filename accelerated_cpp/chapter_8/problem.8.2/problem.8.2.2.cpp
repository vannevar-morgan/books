// implements the "find()" algorithm.
// requires two input iterators.
#include <string>
#include <iostream>
#include <vector>


template <class In, class X>
In find(In beg, In end, const X& x)
{
  // note that if you implemented instead as a binary_find() you would get log(n)log(n) instead of n complexity.
  while(beg != end && *beg != x){
    ++beg;
  }

  return beg;
}

int main()
{
  std::cout << "Testing the implementation of the find() library algorithm...\n" << std::endl;
  std::vector<std::string> words;

  // get some data to perform a search on
  std::cout << "Enter some text: \n";
  std::string s;
  while(std::cin >> s){
    words.push_back(s);
  }

  // reset std::cin
  std::cout << "(press enter)";
  if(!std::cin){
    std::cin.clear();
    std::getline(std::cin, s);
  }

  // get a string to use as a search term
  std::cout << "Enter a string to use as a search term: \n";
  std::cin >> s;

  // use find to perform a search on the text
  std::vector<std::string>::const_iterator search_term_iter = find(words.begin(), words.end(), s);

  // print result to user
  if(search_term_iter != words.end()){
    std::cout << "Found the word.\n" << std::endl;
    // highlight the search term at the location found
    std::vector<std::string>::const_iterator iter = words.begin();
    while(iter != search_term_iter){
      std::cout << *iter++ << " ";
    }
    std::cout << " << " << *search_term_iter << " >> ";
    ++iter;
    while(iter != words.end()){
      std::cout << *iter++ << " ";
    }
    std::cout << std::endl;
  }else{
    std::cout << "Didn't find the word.\n";
  }
  
  return 0;
}
