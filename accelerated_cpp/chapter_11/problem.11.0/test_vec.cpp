#include <iostream>
#include <string>
#include "Vec.hpp"

using namespace std;

int main()
{
  // Make a Vec to test
  Vec<string> words;
  
  // Get some input to work with
  cout << "enter some words: \n";
  string n;
  while(cin >> n){
    words.push_back(n);
  }

  // Print the words back to the user
  // test Vec::iterator
  cout << "printing Vec contents using Vec::iterator..." << endl;
  Vec<string>::iterator iter = words.begin();
  while(iter != words.end()){
    cout << *iter++ << endl;
  }
  cout << endl;

  // test Vec::size()
  cout << "number of words: " << words.size() << endl;

  // test Vec::operator[]() by printing words to user
  cout << "words printed using the index operator: \n";
  for(Vec<string>::size_type i = 0; i != words.size(); ++i){
    cout << words[i] << endl;
  }
  cout << endl;

  /*
  // test Vec::const_iterator
  cout << "test const_iterator...\n";
  Vec<string>::const_iterator c_iter = words.begin();
  while(c_iter != words.end()){
    *c_iter++ = "cat"; // shouldn't compile, const_iterator is of type const T*, can't write through const_iterator
  }
  */
  
  // Print the words back to the user
  cout << "words after modifying assigning \"wreckage brother\" to all elements...\n";
  iter = words.begin();
  while(iter != words.end()){
    *iter++ = "wreckage brother";
  }
  iter = words.begin();
  while(iter != words.end()){
    cout << *iter++ << endl;
  }
  cout << endl;

  // Test other versions of constructors and assignment
  words = Vec<string>(5, "dog");

  // Print the words back to the user
  cout << "words after assigning a new vector created with Vec<string>(size, data) constructor...\n";
  iter = words.begin();
  while(iter != words.end()){
    cout << *iter++ << endl;
  }
  cout << endl;

  // Test other versions of constructors and assignment
  Vec<string> words2(words);

  // Print the words back to the user
  cout << "contents of new vector, words2, after constructing from words...\n";
  iter = words.begin();
  while(iter != words.end()){
    cout << *iter++ << endl;
  }
  cout << endl;

  // Test Vec objects parameterized by other types
  Vec<int> nums;
  Vec<double> dubs;

  // Get some input to work with
  cin.clear();
  cout << "enter some ints: \n";
  int a;
  while(cin >> a){
    nums.push_back(a);
  }

  // Print the ints back to the user
  cout << "your ints: \n";
  Vec<int>::iterator nums_iter = nums.begin();
  while(nums_iter != nums.end()){
    cout << *nums_iter++ << endl;
  }
  cout << endl;

  // Get some input to work with
  cin.clear();
  cout << "enter some doubles: \n";
  double b;
  while(cin >> b){
    dubs.push_back(b);
  }

  // Print the dubs back to the user
  cout << "your dubs: \n";
  Vec<double>::iterator dubs_iter = dubs.begin();
  while(dubs_iter != dubs.end()){
    cout << *dubs_iter++ << endl;
  }
  cout << endl;



}
