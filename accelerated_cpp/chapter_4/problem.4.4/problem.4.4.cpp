/*

-calculate the squares of double values
-write two columns: value, square(value)
-use setw() to manage output and line values in columns
-make the arguments to setw() robust to changes in the number of digits (should automatically print with enough space for larger numbers if necessary)

*/

#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
//using std::pow;

struct num_and_square {
  vector<double> number;
  vector<double> square;
};

void print_output(num_and_square, int prec_size = 0);



int main()
{
  const double n_low = 10.5;
  const int num_data = 100;
  const int n_prec = 4;
  
  // make some data to test with
  num_and_square number_data;
  for (int i = 0; i != num_data; ++i){
    number_data.number.push_back(i*2.5 + n_low);
    number_data.square.push_back(pow(i*2.5 + n_low, 2.0));
  }

  // print the data
  print_output(number_data, n_prec);

  return 0;
}

void print_output(num_and_square data, int prec_size)
{
  assert(prec_size >= 0);
  vector<double>::size_type vec_size;
  vec_size = data.number.size();
  
  // find the required width for the square column
  vector<double>::iterator iter_to_max = std::max_element(data.square.begin(), data.square.end());
  int sq_col_width = 1; // only remains unchanged if data.square contains no values
  if(iter_to_max != data.square.end()){
    sq_col_width = (int)ceil(log10(*iter_to_max)) + 2 + prec_size; // add 1 for first digit, add 1 for a space, add prec_size for any decimals
  }
 
  // find the required width for the numbers column
  vector<double>::iterator iter_to_max_num = std::max_element(data.number.begin(), data.number.end());
  int num_col_width = 1;
  if(iter_to_max_num != data.number.end()){
    num_col_width = (int)ceil(log10(*iter_to_max_num)) + 1 + prec_size; // add 1 for the first digit, add prec_size for any decimals
  }

  cout << endl << "Squares of a number n:" << endl;
  cout << std::fixed;
  cout.precision(prec_size);
  for (vector<int>::size_type i = 0; i != vec_size; ++i){
    cout << setw(num_col_width) << data.number[i] << setw(sq_col_width) << data.square[i] << endl;
  }
  
  //  cout << "max_square: " << max_square << endl;
  //  cout << "sq_col_width: " << sq_col_width << endl;
}
