#include "Str.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  Str a;
  cout << a << endl;

  a = "they live";
  cout << a << endl;

  // get words from command line to test operator>>
  vector<Str> words;
  cout << "enter some words: " << endl;
  while(cin >> a){
    words.push_back(a);
  }
  cin.clear();

  // print to user the words entered
  for(vector<Str>::size_type i = 0; i != words.size(); ++i){
    cout << words[i] << endl;
  }
  cout << endl;

  Str b(10, 'b');
  cout << "b: " << b << endl;

  Str c = "hello world";
  cout << "c: " << c << endl;

  c = b;
  cout << "c assigned b: " << c << endl;

  Str d("const char* constructor");
  cout << "d: " << d << endl;
  cout << "size of d: " << d.size() << endl;
  cout << "is d empty?: " << d.empty() << endl;
  d.clear();
  cout << "cleared d!" << endl;
  cout << "is d empty?: " << d.empty() << endl;

  Str e = "red";
  Str f = "white";
  Str g = e + f;
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  cout << "g = e + f: " << g << endl;
  e += f;
  cout << "e += f: " << e << endl;



  return 0;
}
