/* $4.e/73
   Problem 4-0, Example Program 1
   
   This program asks the user for their name and grades.  Then it computes their grade and prints to screen.  Computes the final grades for any number of students.  It makes use of header files and functions compiled separately.  
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"
#include "analysis_schemes.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


vector<Student_info>
extract_fails(vector<Student_info>& students);

int main()
{
  // students who did and didn't do all their homework
  vector<Student_info> did, didnt;
  
  // read the student records and partition them
  Student_info student;
  while(read(cin, student)){
    if(did_all_hw(student)){
      did.push_back(student);
    }else{
      didnt.push_back(student);
    }
  }
  
  // verify that the analyses will show us something
  if(did.empty()){
    cout << "No student did all their homework!" << endl;
    return 1;
  }
  
  if(didnt.empty()){
    cout << "All students did all their homework!" << endl;
    return 1;
  }
  
  // do the analyses
  write_analysis(cout, "median", median_grade, did, didnt);
  write_analysis(cout, "average", average_grade, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);
  
  // separate passing and failing students
  vector<Student_info> all_students(did.begin(), did.end());
  copy(didnt.begin(), didnt.end(), back_inserter(all_students));
  
  vector<Student_info> failing_students = extract_fails(all_students);
  
  cout << "Passing Students: " << endl;
  for(const Student_info& s : all_students){
    cout << s.name << endl;
  }
  
  cout << "\nFailing Students: " << endl;
  for(const Student_info& s : failing_students){
    cout << s.name << endl;
  }

  return 0;
}


vector<Student_info>
extract_fails(vector<Student_info>& students)
{
  vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
  vector<Student_info> fail(iter, students.end());
  students.erase(iter, students.end());
  
  return fail;
}
