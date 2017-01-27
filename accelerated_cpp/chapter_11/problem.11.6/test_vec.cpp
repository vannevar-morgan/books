#include "Vec.hpp"
#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime> // for time() to use with srand()
#include <iterator> // for back_inserter()
#include <algorithm> // for copy()

using namespace std;

int main()
{
  Vec<int> nums;

  // get some input to work with
  cout << "enter some integers: \n";
  int n;
  while(cin >> n){
    nums.push_back(n);
  }

  // test Vec<>::clear()
  cout << "size of nums: " << nums.size() << endl;
  nums.clear();
  cout << "size of nums after clear: " << nums.size() << endl;

  // get some more input to work with
  cout << "enter some more :) integers: \n";
  cin.clear();
  while(cin >> n){
    nums.push_back(n);
  }

  // test Vec<>::erase() for single element
  cout << "size of nums: " << nums.size() << endl;
  typedef Vec<int>::size_type sz;
  srand(time(0));
  sz a = rand() % nums.size();
  cout << "erasing element at " << a << endl;
  Vec<int>::iterator next_element = nums.erase(nums.begin() + a);
  Vec<int>::const_iterator iter = nums.begin();
  while(iter != nums.end()){
    cout << *iter++ << endl;
  }
  cout << endl << "size of nums after erasing single element: " << nums.size() << endl;
  if(next_element != nums.end()){
    cout << "next element: " << *next_element << endl;
  }else{
    cout << "next element is vector end..." << endl;
  }

  // test Vec<>::erase for range of elements
  cout << "erasing elements in range: [3, 7)" << endl;
  next_element = nums.erase(nums.begin() + 3, nums.begin() + 7);
  iter = nums.begin();
  while(iter != nums.end()){
    cout << *iter++ << endl;
  }
  cout << endl << "size of nums after erasing range of elements: " << nums.size() << endl;
  if(next_element != nums.end()){
    cout << "next element: " << *next_element << endl;
  }else{
    cout << "next element is vector end..." << endl;
  }
  
  // test back_inserter (could also do this for Vec.hpp from problem_11_0)
  cout << "enter some more :) integers: \n";
  cin.clear();
  Vec<int> nums2;
  while(cin >> n){
    nums2.push_back(n);
  }
  std::copy(nums2.begin(), nums2.end(), back_inserter(nums));

  cout << endl << "nums after appending nums2 to the end of nums with back_inserter():" << endl;
  iter = nums.begin();
  while(iter != nums.end()){
    cout << *iter++ << endl;
  }
  cout << endl;
  cout << "size of nums after appending nums2 to the end of nums with back_inserter(): " << nums.size() << endl;
  
  return 0;
}
