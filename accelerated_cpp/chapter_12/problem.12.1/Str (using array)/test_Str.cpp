#include "Str.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  Str a = "hello world";
  cout << "a: " << a << endl;
  
  Str b;
  cout << "b: " << b << endl;
  
  Str c = a;
  cout << "c: " << c << endl;

  
  Str d;
  vector<Str> words;
  cout << "enter some words: ";
  while(cin >> d){
    words.push_back(d);
  }

  cout << "These are the words you entered: " << endl;
  for(vector<Str>::size_type i = 0; i != words.size(); ++i){
    cout << words[i] << endl;
  }
  
  
  Str e = "red";
  Str f = "black";
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  cout << "e + f: " << e + f << endl;

  Str g = e + f;
  cout << "g: " << g << endl;

  e += f;
  cout << "e += f: " << e << endl;

  Str h(10, 'f');
  cout << "h: " << h << endl;
  cout << "using Str(size_type n, char c): " << Str(10, 'a') << endl;
  
  
  string name = "howard hughes";
  Str k(name.begin(), name.end());
  cout << "k: " << k << endl;
  cout << "using template constructor Str(In b, In e): " << Str(name.begin(), name.end()) << endl;
  cout << "number of characters in " << k << ": " << k.size() << endl;
  

  return 0;
}
