/*

-calculate the squares of int values
-write two columns: value, square(value)
-use setw() to manage output and line values in columns
-make the arguments to setw() robust to changes in the number of digits (should automatically print with enough space for larger numbers if necessary)

*/

#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
//using std::pow;

struct num_and_square {
  vector<int> number;
  vector<long> square;
};

void print_output(num_and_square);



int main()
{
  const int n_low = 999950;
  const int n_high = 1000000;
  
  num_and_square number_data;
  for (int i = n_low; i != n_high+1; ++i){
    number_data.number.push_back(i);
    number_data.square.push_back((long)pow((double)i, 2.0));
  }

  print_output(number_data);

  return 0;
}

void print_output(num_and_square data)
{
  vector<int>::size_type vec_size;
  vec_size = data.number.size();
  vector<long>::iterator iter_to_max = std::max_element(data.square.begin(), data.square.end());
  long max_square = 1;
  if(iter_to_max != data.square.end()){
    max_square = *iter_to_max;
  }
  int sq_col_width = ceil(log10(max_square)) + 2;
  
  vector<int>::iterator iter_to_max_num = std::max_element(data.number.begin(), data.number.end());
  int max_num = 1;
  if(iter_to_max_num != data.number.end()){
    max_num = *iter_to_max_num;
  }
  int num_col_width = ceil(log10(max_num)) + 1;

  
  cout << endl << "Squares of a number n:" << endl;
  for (vector<int>::size_type i = 0; i != vec_size; ++i){
    cout << setw(num_col_width) << data.number[i] << setw(sq_col_width) << data.square[i] << endl;
  }
  
  //  cout << "max_square: " << max_square << endl;
  //  cout << "sq_col_width: " << sq_col_width << endl;
}
