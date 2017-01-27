/*
 * Accelerated C++, Problem 6.0, Pg. 103, Splitting strings
 */

#include "List.hpp"
#include <iostream>
#include <cctype> // for isspace()
#include <string>
#include <algorithm> // for find_if()

//using namespace std;

bool space(char c);
bool not_space(char c);
List<std::string> split(const std::string& str);

int main(){
  // get some text from the user to parse.
  std::cout << "Enter some text to split into words: " << std::endl;
  std::string s;
  getline(std::cin, s);
  
  // split the text to words
  List<std::string> words = split(s);
  
  // print each word
  std::cout << "\nall words entered: " << std::endl;
  for(const std::string w : words){
    std::cout << w << std::endl;
  }

  // Show that List can be used with types other than string  
  List<int> nums;
  std::cout << "\nEnter some ints: " << std::endl;
  std::cin.clear();
  int n;
  while(std::cin >> n){
    nums.push_back(n);
  }

  std::cout << "\nThese are the numbers you entered: " << std::endl;
  for(auto& i : nums){
    std::cout << i << std::endl;
  }

  // Show that List can be used with library algorithms that only require the capabilities of a bidirectional-iterator or less.
  std::reverse(nums.begin(), nums.end());
  std::cout << "\nThese are the (reversed) numbers you entered: " << std::endl;
  for(auto& i : nums){
    std::cout << i << std::endl;
  }


  
  return 0;
}


bool space(char c){
  return isspace(c);
}


bool not_space(char c){
  return !isspace(c);
}


List<std::string> split(const std::string& str){
  typedef std::string::const_iterator iter;
  List<std::string> ret;
  
  iter i = str.begin();
  while(i != str.end()){
    // ignore leading blanks
    i = find_if(i, str.end(), not_space);
    
    // find the end of the next word
    iter j = find_if(i, str.end(), space);
    
    // copy the characters in [i, j)
    if(i != str.end()){
      ret.push_back(std::string(i, j));
    }
    
    i = j;
  }
  
  return ret;
}
