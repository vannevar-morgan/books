/* $3.e/49
   Problem 3-0, Example Program 2
   This program asks the user for their name and grades.  Then it computes their grade and prints to screen.

   It is similar to Example Program 1 but makes improvements by basing the homework grade on the median, using the vector type
   to contain the homework grades, using the sort() method of the vector type to sort the vector before computing the median, 
   and various other functions.

   This is a good program to study as an introduction to the vector type.
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
  // ask for and read the student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for and read the homework grades
  cout << "Enter all your homework grades, "
    "followed by EOF: ";

  vector<double> homework;
  double x;

  //  invariant: 'homework' contains all the homework grades read so far
  while (cin >> x)
    homework.push_back(x);

  // check that the student entered some homework grades
  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  if (size == 0) {
    cout << endl << "You must enter your grades. "
      "Please try again." << endl;
    return 1;
  }

  //sort the grades
  sort(homework.begin(), homework.end());

  // compute the median homework grade
  vec_sz mid = size / 2;
  double median;
  median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

  // compute and write the final grade
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
  << 0.2 * midterm + 0.4 * final + 0.4 * median
       << setprecision(prec) << endl;

  return 0;
}
