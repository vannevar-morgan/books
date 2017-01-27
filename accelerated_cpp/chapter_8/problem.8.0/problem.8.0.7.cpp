#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
  while(begin < end){
    // find the midpoint of the range
    Ran mid = begin + (end - begin) / 2;

    // see which part of the range contains x; keep looking only in that part
    if(x < *mid){
      end = mid;
    }else if(*mid < x){
      begin = mid + 1;
    }else{
      return true;
    }
  }

  return false;
}

int main()
{
  std::vector<std::string> words;

  // get some text
  std::cout << "Enter some text: \n";
  std::string s;
  while(std::cin >> s){
    words.push_back(s);
  }

  // reset std::cin
  std::cout << "(press enter)\n";
  if(!std::cin){
    std::cin.clear();
    std::getline(std::cin, s);
  }

  // print the original, unsorted text
  std::cout << "\nThis is the text you entered:" << std::endl;
  std::vector<std::string>::const_iterator iter;
  for(iter = words.begin(); iter != words.end(); ++iter){
    std::cout << *iter << "\n";
  }
  std::cout << std::endl;

  // get a search term to search the text
  std::string search_term;
  std::cout << "Enter a word to search for in the text: \n";
  std::cin >> search_term;

  // sort the text before searching
  sort(words.begin(), words.end());

  // search the text for the search term, using binary search template
  bool search_success = ::binary_search(words.begin(), words.end(), search_term);

  // output the results of the search to console
  if(search_success){
    std::cout << "Word was located!\n";
  }else{
    std::cout << "Didn't see the word...\n";
  }

  return 0;
}
