/* $3.e/49
   Problem 3-6
   This program asks the user for their name and grades.  Then it computes their grade and prints to screen.
   It's the same as Problem 3-0, Example Program 1 except when calculating the final grade it only adds the homework portion of the grade if the student did at least one homework.  It prevents the divide by zero error in the original program when the student does no homework.
*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

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

  // ask for the homework grades
  cout << "Enter all your homework grades, "
    "followed by EOF: ";

  // the number and sum of grades read so far
  int count = 0;
  double sum = 0;

  // a variable into which to read
  double x;

  // invariant:
  //   we have read count grades so far, and
  //   sum is the sum of the first 'count' grades
  while (cin >> x){
    ++count;
    sum += x;
  }

  double final_grade = 0.2 * midterm + 0.4 * final;
  if(count > 0){
    // only add the homework grade if the student did homework
    final_grade += 0.4 * sum / count;    
  }
  
  // write the result
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << final_grade
       << setprecision(prec) << endl;

  return 0;
}
