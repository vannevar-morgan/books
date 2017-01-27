#include "Vec.hpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
  // initialize a Vec from a string
  string s = "hello world";
  Vec<char> vec_from_str(s.begin(), s.end());

  // print the state of the Vec after initialization
  cout << "size of vec_from_str: " << vec_from_str.size() << endl;
  cout << endl << "Vec initialized from string s = \"" << s << "\": " << endl;
  for(Vec<char>::size_type i = 0; i < vec_from_str.size(); ++i){
    cout << vec_from_str[i] << endl;
  }
  cout << endl;

  return 0;
}
