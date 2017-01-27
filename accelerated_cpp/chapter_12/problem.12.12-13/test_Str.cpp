#include "Str.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
  cout << "*************************BEGIN PROGRAM*************************" << endl;
  // test null termination of empty string
  cout << "testing null termination for empty string..." << endl;
  string a2;
  cout << "std::string a2[0]: " << a2[0] << endl;

  Str b2;
  cout << "Str b2[0]: " << b2[0] << endl;

  Str c2("");
  cout << "Str c2[0]: " << c2[0] << endl;
  cout << "finished test of null termination for empty string." << endl;
  // finished test of null termination of empty string

  Str a;
  cout << "a (empty): " << a << endl;

  a = "they live";
  cout << "a (const char*): " << a << endl;
  cout << "clearing a..." << endl;
  a.clear();
  cout << "a after being cleared: " << a << endl;

  // get words from command line to test operator>>
  cout << "Testing operator>>" << endl;
  vector<Str> words;
  cout << endl << "Enter some words to test operator>> : " << endl;
  while(cin >> a){
    words.push_back(a);
  }
  cin.clear();

  // print to user the words entered
  cout << "These are the words you entered: " << endl;
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
  cout << "size of d: " << d.size() << endl;

  // testing Str concatenation
  cout << endl << "Testing Str concatenation..." << endl;
  Str concat1 = "red";
  Str concat2 = "white";
  Str concat3 = concat1 + concat2;
  cout << "concat1: \"" << concat1 << "\"" << endl;
  cout << "concat2: \"" << concat2 << "\"" << endl;
  cout << "concat3 = concat1 + concat2: \"" << concat3 << "\"" << endl;
  concat1 += concat2;
  cout << "concat1 += concat2: \"" << concat1 << "\"" << endl;
  // test concatenation without relying on the conversion operators (problem 12.5)
  cout << endl << "Testing concatenation without relying on the conversion operators (problem 12.5)" << endl;
  concat2 += " gold";
  cout << "concat2 += \" gold\": \"" << concat2 << "\"" << endl;
  Str concat4;
  concat4 = concat3 + " hello";
  cout << "concat4 = concat3 + \" hello\": \"" << concat4 << "\"" << endl;
  
  Str concat5;
  concat5 = "hello " + concat3;
  cout << "concat5 = \"hello \" + concat3: \"" << concat5 << "\"" << endl;
  // finished testing Str concatenation

  const Str filename = "test_output.txt";
  ofstream os(filename.c_str());
  cout << endl << "enter some text to write to file: " << endl;
  while(cin >> a){
    os << a << endl;
  }

  // testing Str::copy()
  cout << endl << "Testing Str::copy()..." << endl;
  Str::size_type array_sz = 16;
  char* temp_copy = new char[array_sz];
  Str::size_type num_copied = filename.copy(temp_copy, 6);
  //  *(temp_copy + array_sz - 1) = '\0';
  cout << "number of characters copied from 'filename': " << num_copied << endl;
  printf("%s", temp_copy);
  cout << endl;

  num_copied = filename.copy(temp_copy, 100);
  //  *(temp_copy + array_sz - 1) = '\0';
  cout << "number of characters copied from 'filename': " << num_copied << endl;
  printf("%s", temp_copy);
  cout << endl;

  num_copied = filename.copy(temp_copy, 100, 4);
  //  *(temp_copy + array_sz - 1) = '\0';
  cout << "number of characters copied from 'filename': " << num_copied << endl;
  printf("%s", temp_copy); // should print "_output.txt.txt"
  cout << endl;

  try{
    num_copied = filename.copy(temp_copy, 6, 50); // will throw an exception because index 50 is outside the range of the string
    //  *(temp_copy + array_sz - 1) = '\0';
    cout << "number of characters copied from 'filename': " << num_copied << endl;
    printf("%s", temp_copy);
    cout << endl;
  }catch(out_of_range e){
    cout << "error while copying string: \n" << e.what() << endl;
  }
  
  delete[] temp_copy;
  // finished testing Str::copy()

  // testing relational, equality, and inequality operators (problem 12.3, 12.4)
  cout << endl << "Testing relational, equality, and inequality operators (problem 12.3, 12.4)..." << endl;
  Str r1 = "cat";
  Str r2 = "cat";
  Str r3 = "dog";
  cout << "r1 == r2? " << (r1 == r2) << endl;
  cout << "r1 != r2? " << (r1 != r2) << endl;
  cout << "r1 == r3? " << (r1 == r3) << endl;
  cout << "r1 != r3? " << (r1 != r3) << endl;
  cout << "r1 < r2? " << (r1 < r2) << endl;
  cout << "r1 < r3? " << (r1 < r3) << endl;
  cout << "r1 > r2? " << (r1 > r2) << endl;
  cout << "r1 > r3? " << (r1 > r3) << endl;
  cout << "r1 <= r2? " << (r1 <= r2) << endl;
  cout << "r1 <= r3? " << (r1 <= r3) << endl;
  cout << "r1 >= r2? " << (r1 >= r2) << endl;
  cout << "r1 >= r3? " << (r1 >= r3) << endl;
  // finished testing relational, equality, and inequality operators

  // testing bool conversion operator for Str (problem 12.6)
  cout << endl << "Testing bool conversion operator for Str (problem 12.6)..." << endl;
  Str boolStr1;
  Str boolStr2 = "hello";
  cout << "boolStr1: \"" << boolStr1 << "\"" << endl;
  cout << "boolStr2: \"" << boolStr2 << "\"" << endl;
  cout << "boolStr1 as bool: ";
  if(boolStr1){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
  cout << "boolStr2 as bool: ";
  if(boolStr2){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
  // finished testing conversion operator for Str
  
  // testing getline nonmember function of Str (problem 12.8)
  cout << endl << "Testing getline nonmember function of Str (problem 12.8)..." << endl;
  Str gl;
  vector<Str> lines;
  cin.clear();
  cout << endl << "Enter some lines of text to test getline(): " << endl;
  while(getline(cin, gl)){
    lines.push_back(gl);
  }
  cin.clear();

  cout << endl << "These are the lines you entered: " << endl;
  for(vector<Str>::size_type i = 0; i != lines.size(); ++i){
    cout << lines[i] << endl;
  }
  // finished testing getline nonmember function of Str

  // test template constructor of Str
  cout << endl << "Testing template constructor of Str..." << endl;
  Str tmplt1 = "hello";
  cout << "Str that is constructed from: \"" << tmplt1 << "\"" << endl;
  Str tmplt2(tmplt1.begin() + 3, tmplt1.end());
  cout << "Str constructed using template constructor: \"" << tmplt2 << "\"" << endl;
  // finished testing template constructor of Str

  // test Str::insert()
  cout << endl << "Testing Str::insert()..." << endl;
  cin.clear();
  cout << "Enter some characters for Str1: " << endl;
  Str test_insert1;
  getline(cin, test_insert1);
  Str test_insert2;
  cout << endl << "Enter some characters for Str2: " << endl;
  getline(cin, test_insert2);
  cout << endl << "test_insert1: \"" << test_insert1 << "\"" << endl;
  cout << endl << "test_insert2: \"" << test_insert2 << "\"" << endl;
  Str::size_type mid = test_insert1.size() / 2;
  test_insert1.insert(test_insert1.begin() + mid, test_insert2.begin(), test_insert2.end());
  cout << endl << "test_insert1 with test_insert2 inserted: \"" << test_insert1 << "\"" << endl;
  // finished testing Str::insert()

  cout << "*************************END PROGRAM*************************" << endl;
  
  return 0;
}
