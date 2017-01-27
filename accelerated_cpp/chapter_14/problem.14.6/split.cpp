#include "Str.hpp"
#include <vector>
#include <iostream>
#include <cctype> // for isspace()
#include <algorithm> // for find_if()


using namespace std;

vector<Str> split_88(const Str& s);
vector<Str> split_103(const Str& s);
bool space(char c);
bool not_space(char c);


int main()
{
  // get some input to act on
  Str s;
  vector<Str> words;
  cout << "enter some words: " << endl;
  getline(cin, s);

  // print text entered
  cout << "this is what you entered: " << endl;
  cout << s << endl;

  
  // print words split using split_88()
  words = split_88(s);
  cout << endl << "these are the words you entered using split_88(): " << endl;
  for(vector<Str>::size_type i = 0; i != words.size(); ++i){
    cout << words[i] << endl;
  }
  
  
  // print words split using split_103()
  words = split_103(s);
  cout << endl << "these are the words you entered using split_103(): " << endl;
  for(vector<Str>::size_type i = 0; i != words.size(); ++i){
    cout << words[i] << endl;
  }
  cout << endl;
  
  
  return 0;
}


vector<Str> split_88(const Str& s)
{
  /*
   * split function as defined on page 88, Section 5.6
   */
  
  vector<Str> ret;
  typedef Str::size_type string_size;
  string_size i = 0;
  
  // invariant: we have processed characters [original value of i, i)
  while(i != s.size()){
    // ignore leading blanks
    // invariant: characters in range [original i, current i) are all spaces
    while(i != s.size() && isspace(s[i])){ ++i; }
    
    // find end of next word
    string_size j = i;
    // invariant: none of the characters in range [original j, current j) is a space
    while(j != s.size() && !isspace(s[j])){ ++j; }
    
    // if we found some nonwhitespace characters
    if(i != j){
      // copy from s starting at i and taking j - i characters
      ret.push_back( Str(s.begin() + i, s.begin() + j) );
      i = j;
    }
  }
  
  return ret;
}


bool space(char c)
{
  /*
   * space function as defined on page 103, Section 6.1.1
   */
  
  return isspace(c);
}


bool not_space(char c)
{
  /*
   * not_space function as defined on page 103, Section 6.1.1
   */
  
  return !isspace(c);
}


vector<Str> split_103(const Str& s)
{
  /*
   * split function as defined on page 103, Section 6.1.1
   */
  
  typedef Str::const_iterator iter;
  vector<Str> ret;
  
  iter i = s.begin();
  while(i != s.end()){
    // ignore leading blanks
    i = find_if(i, s.end(), not_space);
    
    // find end of next word
    iter j = find_if(i, s.end(), space);
    
    // copy the characters in [i, j)
    if(i != s.end()){
      ret.push_back( Str(i, j) );
    }

    i = j;
  }
  
  return ret;
}
