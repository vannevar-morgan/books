#include "Str.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  cout << "Testing Str(const char*)..." << endl;
  Str a = "hello world";
  cout << "a: \"" << a << "\"" << endl;
  
  cout << endl << "Testing Str default constructor..." << endl;
  Str b;
  cout << "b: \"" << b << "\"" << endl;
  
  cout << endl << "Testing the copy constructor..." << endl;
  Str c = a;
  cout << "c: \"" << c << "\"" << endl;

  cout << endl << "Testing operator>>..." << endl;
  Str d;
  vector<Str> words;
  cout << "enter some words: ";
  while(cin >> d){
    words.push_back(d);
  }

  cout << endl << "These are the words you entered: " << endl;
  for(vector<Str>::size_type i = 0; i != words.size(); ++i){
    cout << "\"" << words[i] << "\"" << endl;
  }

  cout << endl << "Testing Str concatenations..." << endl;
  Str e = "red";
  Str f = "black";
  cout << "e: \"" << e << "\"" << endl;
  cout << "f: \"" << f << "\"" << endl;
  cout << "e + f: \"" << e + f << "\"" << endl;

  Str g = e + f;
  cout << "g: \"" << g << "\"" << endl;

  e += f;
  cout << "e += f: \"" << e << "\"" << endl;
  
  Str h(10, 'f');
  cout << "h: \"" << h << "\"" << endl;

  cout << endl << "Testing Str(size_type n, char c)..." << endl;
  cout << "\"" << Str(10, 'a') << "\"" << endl;
  
  cout << endl << "Testing template <class In> Str(In b, In e)..." << endl;
  string name = "howard hughes";
  Str k(name.begin(), name.end());
  cout << "k: \"" << k << "\"" << endl;

  cout << "Testing Str::size()..." << endl;
  cout << "number of characters in " << k << ": " << k.size() << endl;
  
  return 0;
}
