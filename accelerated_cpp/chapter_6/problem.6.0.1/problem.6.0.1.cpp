/*
 * Accelerated C++, Problem 6.0, Pg. 103, Splitting strings
 */

#include <iostream>
#include <cctype> // for isspace()
#include <vector>
#include <string>
#include <algorithm> // for find_if()

using namespace std;

bool space(char c);
bool not_space(char c);
vector<string> split(const string& str);

int main(){
  // get some text from the user to parse.
  cout << "enter some text to split into words: " << endl;
  string s;
  getline(cin, s);
  
  // split the text to words
  vector<string> words = split(s);
  
  // print each word
  cout << "\nall words entered: " << endl;
  for(const string w : words){
    cout << w << endl;
  }
  
  
  return 0;
}


bool space(char c){
  return isspace(c);
}


bool not_space(char c){
  return !isspace(c);
}


vector<string> split(const string& str){
  typedef string::const_iterator iter;
  vector<string> ret;
  
  iter i = str.begin();
  while(i != str.end()){
    // ignore leading blanks
    i = find_if(i, str.end(), not_space);
    
    // find the end of the next word
    iter j = find_if(i, str.end(), space);
    
    // copy the characters in [i, j)
    if(i != str.end()){
      ret.push_back(string(i, j));
    }
    
    i = j;
  }
  
  return ret;
}
