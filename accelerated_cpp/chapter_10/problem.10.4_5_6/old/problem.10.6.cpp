
#include "String_list.hpp"
#include <iostream>
#include <string>
#include <cstddef> // for size_t
#include <vector>
//#include <iterator> // for back_inserter()
//#include <algorithm> // for copy()

int main()
{
  String_list words;  

  // get some input to act on
  std::cout << "enter some words: \n";
  std::string w;
  while(std::cin >> w){
    words.push_back(w);
  }

  // print words to user
  auto iter = words.begin();
  for(; iter < words.end(); ++iter){
    std::cout << *iter << std::endl;
  }

  // clear the list and print size
  std::cout << "clearing list\n";
  words.clear();
  std::cout << "list size after clearing: " << words.size() << std::endl;

  // get some input to act on
  std::cout << "enter some words: \n";
  std::cin.clear();
  while(std::cin >> w){
    words.push_back(w);
  }

  // print words to user
  iter = words.begin();
  for(; iter < words.end(); ++iter){
    std::cout << *iter << std::endl;
  }
  std::cout << "list size: " << words.size() << std::endl;

  // verify the iterator type for String_list
  String_list::iterator slist_iter = words.end();

  // erase some elements from String_list
  slist_iter -= 3;
  words.erase(words.begin(), words.end());
  std::cout << "size of words after erase(): " << words.size() << std::endl;
  std::cout << "testing access to erased elements: " << std::endl;
  std::cout << *slist_iter << std::endl;

  /*
  // get some input to act on
  std::vector<std::string> animals;
  std::cout << "enter some types of animals: \n";
  std::cin.clear();
  while(std::cin >> w){
    animals.push_back(w);
  }

  // copy animals to words using back_inserter()
  std::copy(animals.begin(), animals.end(), std::back_inserter(words));
  */


  return 0;
}


