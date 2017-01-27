/*
 * Accelerated C++, Problem 6.0, Pg. 105, Palindromes
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_palindrome(const std::string& s);

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "usage: ./palindrome word" << endl;
    return -1;
  }
  
  bool word_is_palindrome = is_palindrome(string(argv[1]));
  if(word_is_palindrome){
    cout << "it's a palindrome..." << endl;
  }else{
    cout << "not a palindrome..." << endl;
  }
  
  return 0;
}


bool is_palindrome(const std::string& s){
  return equal(s.begin(), s.end(), s.rbegin());
}
