#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

int main ()
{
  // get some words to concatenate together.
  std::cout << "enter some text lines to concatenate together: " << std::endl;
  std::vector<std::string> data;
  std::string s;
  while (std::getline(std::cin, s)) {
    data.push_back(s);
    data.push_back(" ");
  }

  // use std::accumulate() to concatenate all the words together.
  std::string a = "";
  a = std::accumulate(data.begin(), data.end(), a);
  std::cout << std::endl << "Concatenated lines..." << std::endl << a << std::endl;
  
  return 0;
}
