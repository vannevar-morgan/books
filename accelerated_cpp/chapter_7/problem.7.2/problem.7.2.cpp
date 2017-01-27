/* $4.2.3/64
   Problem 4-0
   
   This program asks the user for their name and grades.  Then it computes their grade and prints to screen.  Computes the final grades for any number of students.  It makes use of header files and functions compiled separately.  
*/

#include <map>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::map;
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
  map<char, int> letter_grades;
  cout << endl;
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name
	 << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      ++letter_grades[students[i].letter_grade]; // increment the count for the letter grade of the student
      cout << "\t(" << students[i].letter_grade << ")\t";
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec);
    }catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  // write the number of students receiving each letter grade
  for(auto& p : letter_grades){
    cout << "Number of students receiving " << p.first << ":\t" << p.second << endl;
  }
  cout << endl;
 
  return 0;
}
