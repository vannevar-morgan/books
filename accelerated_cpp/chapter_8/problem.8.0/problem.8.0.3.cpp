#include <iostream>
#include <vector>
#include <string>


template <class In, class X>
In find(In begin, In end, const X& x)
{
  while(begin != end && *begin != x){
    ++begin;
  }
  return begin;
}

/*
// recursive version
template <class In, class X>
In find(In begin, In end, const X& x)
{
  if(begin == end || *begin == x){
    return begin;
  }else{
    return find(++begin, end, x);
  }
}
*/

int main()
{
  std::vector<std::string> words;
  std::cout << "Enter some words: " << std::endl;
  std::string s;
  while(std::cin >> s){
    words.push_back(s);
  }

  std::cout << "(Press enter)" << std::endl;
  if(!std::cin){
    std::cin.clear();
    std::getline(std::cin, s);
  }
  
  std::cout << "Enter a word to search for: " << std::endl;
  std::cin >> s;

  std::vector<std::string>::const_iterator iter = find(words.begin(), words.end(), s);
  if(iter != words.end()){
    std::cout << "Found the word" << std::endl;
  }else{
    std::cout << "Couldn't find the word" << std::endl;
  }

  return 0;
}
