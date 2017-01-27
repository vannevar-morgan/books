#include <iostream>
#include <vector>
#include <string>


template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
  while(beg != end){
    if(*beg == x){
      *beg = y;
    }
    ++beg;
  }
}


int main()
{
  std::cout << "do a find replace\n";
  std::vector<std::string> text;

  // get some text to do a find-replace on
  std::cout << "Enter some text: \n";
  std::string s;
  while(std::cin >> s){
    text.push_back(s);
  }

  // need to reset the std::cin stream
  std::cout << "(press enter)\n";
  if(!std::cin){
    std::cin.clear();
    std::getline(std::cin, s);
  }
  
  // get the old string to find, and the new string to replace with
  std::string old_string, new_string;
  std::cout << "Enter a string to find in the text: \n";
  std::cin >> old_string;
  std::cout << "Enter a string to replace with: \n";
  std::cin >> new_string;

  // do the find-replace
  replace(text.begin(), text.end(), old_string, new_string);

  // output the new text to console
  std::cout << "\n";
  std::cout << *text.begin();
  std::vector<std::string>::const_iterator iter;
  for(iter = (text.begin() + 1); iter != text.end(); ++iter){
    std::cout << " " << *iter;
  }
  std::cout << "\n";

  
  return 0;
}
