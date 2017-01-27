/* $4.e/73
   Problem 4-1
   
   This program takes a string input and returns the length of the longest and the shortest string in its input.
*/


#include "Student_info.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){
  Student_info s;
  s.name = "tom";
  cout << "student name: " << s.name << endl;

  // int maxlen;
  // maxlen = max(s.name.size(), maxlen); // won't work because types are different, s.name.size() is std::string::size_type but maxlen is int.
  
  string::size_type maxlen = 0; // note that you need to initialize maxlen to zero before calling max() orelse maxlen will be the default value for string::size_type (on my system this is about 140721119829504.  i think it varies with available memory, implementation specific.)
  cout << "maxlen: " << maxlen << endl;
  maxlen = max(s.name.size(), maxlen);
  cout << "maxlen: " << maxlen << endl;
  

  return 0;
}
