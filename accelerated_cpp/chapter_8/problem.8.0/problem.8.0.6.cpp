#include <iostream>
#include <string>
#include <vector>


template <class Bi>
void reverse(Bi beg, Bi end)
{
  while(beg != end){
    --end;
    if(beg != end){
      swap(*beg++, *end);
    }
  }
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
  
  // reverse the text
  reverse(words.begin(), words.end());

  // write the reversed text to the console
  std::cout << "\n" << *words.begin();
  std::vector<std::string>::const_iterator iter;
  for(iter = words.begin() + 1; iter != words.end(); ++iter){
    std::cout << " " << *iter;
  }
  std::cout << "\n";


  return 0;
}
