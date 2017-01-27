/* $4.e/73
   Problem 4-0, Example Program 1
   
   This program asks the user for their name and grades.  Then it computes their grade and prints to screen.  Computes the final grades for any number of students.  It makes use of header files and functions compiled separately.  
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;   // the length of the longest name

  // read and store all the students' data.
  while (read(cin, record)){
    // find the length of the longest name
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }
  
  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != students.size(); i++){
    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name
	 << string(maxlen + 1 - students[i].name.size(), ' ');

    // write the grade
    try {
      streamsize prec = cout.precision();
      cout << setprecision(3) << students[i].final_grade
	   << setprecision(prec);
    }catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }
 
  return 0;
}
