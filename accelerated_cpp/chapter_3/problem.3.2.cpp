/* $3.e/49
   Problem 3-2
   This program takes input of a set of integers and prints the quartiles to screen.

*/

#include <algorithm>
#include <iostream>
#include <string>
//#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
//using std::string;
using std::sort;

bool reverse_compare(const int i, const int j);

int main()
{

  //ask the user for a list of integers
  cout << "\nprinting quartiles of a list of integers..." << endl;
  cout << "Enter 4 or more integers, followed by EOF: " << endl;
  
  vector<int> my_numbers;
  int x;
  
  while (cin >> x)
    my_numbers.push_back(x);

  //check to see that the vector has at least one number in it
  typedef vector<int>::size_type vec_size;

  vec_size num_sz = my_numbers.size();
  if (num_sz < 4) {
    cout << "\nyou didn't enter enough integers to test on..." << endl;
    return 1;
  }

  //sort the numbers in nondecreasing order
  sort(my_numbers.begin(), my_numbers.end(), reverse_compare);

  //print the quartiles to screen
  vec_size q12 = num_sz / 4;
  vec_size q23 = q12 * 2;
  vec_size q34 = q12 * 3;
  
  cout << "first quarter: " << endl;
  for(vec_size i = 0; i < q12; ++i){
    cout << my_numbers[i] << endl;
  }
  
  cout << "\nsecond quarter: " << endl;
  for(vec_size i = q12; i < q23; ++i){
    cout << my_numbers[i] << endl;
  }
  
  cout << "\nthird quarter: " << endl;
  for(vec_size i = q23; i < q34; ++i){
    cout << my_numbers[i] << endl;
  }
  
  cout << "\nfourth quarter: " << endl;
  for(vec_size i = q34; i < num_sz; ++i){
    cout << my_numbers[i] << endl;
  }

}

bool reverse_compare(const int i, const int j)
{
  return (i > j);
}
