#include "Vec.hpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
  // test Vec::insert(), problem 12.12
  cout << "Testing Vec::insert()..." << endl;
  // get some strings to form the initial vector
  string s;
  Vec<string> words1;
  cout << "Enter some words for the first vector: " << endl;
  while(cin >> s){
    words1.push_back(s);
  }
  cin.clear();

  // get some strings to form a second vector
  Vec<string> words2;
  cout << endl << "Enter some words for the second vector: " << endl;
  while(cin >> s){
    words2.push_back(s);
  }

  // print the words in words1
  cout << endl << "words in the first vector: " << endl;
  for(Vec<string>::size_type i = 0; i < words1.size(); ++i){
    cout << words1[i] << endl;
  }
  
  // print the words in words2
  cout << endl << "words in the second vector: " << endl;
  for(Vec<string>::size_type i = 0; i < words2.size(); ++i){
    cout << words2[i] << endl;
  }

  // insert elements of words2 into words1
  Vec<string>::size_type insertion_point = words1.size() / 2;
  words1.insert(words1.begin() + insertion_point, words2.begin(), words2.end());
  
  // print the words in words1 after insertion of words2
  cout << endl << "After inserting words2 into words1 at index " << insertion_point << " words1 is:" << endl;
  for(Vec<string>::size_type i = 0; i < words1.size(); ++i){
    cout << words1[i] << endl;
  }  
  cout << endl;
  // finished testing Vec::insert()

  // test Vec<T>::assign(), problem 12.13
  cout << endl << "Testing Vec<T>::assign()..." << endl;
  Vec<int> test_assign;
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
  
  
  // get some input to work with
  cout << endl << "Enter some integers: " << endl;
  int n;
  cin.clear();
  while(cin >> n){
    test_assign.push_back(n);
  }
  
  // print the numbers prior to calling Vec<T>::assign()
  cout << endl << "These are the numbers in the vector BEFORE calling Vec<T>::assign(): " << endl;
  for(Vec<int>::size_type i = 0; i != test_assign.size(); ++i){
    cout << test_assign[i] << endl;
  }

  test_assign.assign(numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));
  
  // print the numbers after calling Vec<T>::assign()
  cout << endl << "These are the numbers in the vector AFTER calling Vec<T>::assign(): " << endl;
  for(Vec<int>::size_type i = 0; i != test_assign.size(); ++i){
    cout << test_assign[i] << endl;
  }

  // finished testing Vec<T>::assign()


  return 0;
}
