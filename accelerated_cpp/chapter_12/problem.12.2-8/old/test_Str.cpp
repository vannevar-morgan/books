#include "Str.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  // test null termination of empty string
  cout << "testing null termination for empty string..." << endl;
  string a2;
  cout << "std::string a2[0]: " << a2[0] << endl;

  cout << "...not currently testing indexing into a default constructed Str... uncomment to test...(will segfault because this Str version isn't null terminated...)" << endl;
  //  Str b2;
  //  cout << "Str b2[0]: " << b2[0] << endl; // will segfault because Str is not null terminated, means we're indexing into a null char*, uncomment to test.

  Str c2("");
  cout << "Str c2[0]: " << c2[0] << endl;
  cout << "finished test of null termination for empty string." << endl;
  // finished test of null termination of empty string

  Str a;
  cout << a << endl;

  a = "they live";
  cout << a << endl;
  cout << "clearing a..." << endl;
  a.clear();
  cout << "a after being cleared: " << a << endl;

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

  const Str filename = "test_output.txt";
  ofstream os(filename.c_str());
  cout << "enter some text to write to file: " << endl;
  while(cin >> a){
    os << a << endl;
  }


  return 0;
}
