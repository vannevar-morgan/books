/*

-calculate the squares of int values 1 - 100
-write two columns: value, square(value)
-use setw() to manage output and line values in columns

*/

#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
//using std::pow;

struct num_and_square {
  vector<int> number;
  vector<int> square;
};

void print_output(num_and_square);



int main()
{
  const int n_low = 1;
  const int n_high = 100;
  
  num_and_square number_data;
  for (int i = n_low; i != n_high+1; ++i){
    number_data.number.push_back(i);
    number_data.square.push_back((int)pow((double)i, (double)2));
  }

  print_output(number_data);

  return 0;
}

void print_output(num_and_square data)
{
  vector<int>::size_type vec_size;
  vec_size = data.number.size();
  cout << endl << "Squares of a number n:" << endl;
  for (vector<int>::size_type i = 0; i != vec_size; ++i){
    cout << setw(5) << data.number[i] << setw(7) << data.square[i] << endl;
  }

}
