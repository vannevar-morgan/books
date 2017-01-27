#include "Str.hpp"
#include "Vec.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  cout << "Testing Str class..." << endl;
  cout << "\nStr constructed from string literal ('hello world'):" << endl;
  Str a = "hello world";
  cout << "\ta: " << a << endl;
  
  cout << "\nDefault constructed Str (should be blank):" << endl;
  Str b;
  cout << "\tb: " << b << endl;
  
  cout << "\nStr constructed using the copy constructor (Str c = a):" << endl;
  Str c = a;
  cout << "\tc: " << c << endl;

  Str d;
  Vec<Str> words;
  cout << "\nEnter some words to test with: ";
  while(cin >> d){
    words.push_back(d);
  }

  cout << "\nThese are the words you entered: " << endl;
  for(Vec<Str>::size_type i = 0; i != words.size(); ++i){
    cout << words[i] << endl;
  }

  cout << "\nTesting operator+():" << endl;
  Str e = "red";
  Str f = "black";
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  Str g = e + "hello";
  cout << "\te + 'hello': " << e + "hello" << endl;
  g = "hello" + e;
  cout << "\t'hello' + e: " << "hello" + e << endl;
  g = e + f;
  cout << "\tg = e + f: " << g << endl;

  cout << "\nTesting operator+=():" << endl;
  e += f;
  cout << "\te += f: " << e << endl;

  cout << "\nTesting Str(size_type n, char c) constructor (Str h(10, 'f')):" << endl;
  Str h(10, 'f');
  cout << "\th: " << h << endl;

  string name = "adolf hitler";
  cout << "\nTesting template<class In> Str(In b, In e):" << endl;
  Str k(name.begin(), name.end());
  cout << "\tk: " << k << endl;
  cout << "\nTesting Str::size()" << endl;
  cout << "\tnumber of characters in '" << k << "': " << k.size() << endl;


  return 0;
}
