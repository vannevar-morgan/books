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
#include <ctime>
#include "grade.h"
#include "Student_info.h"

using namespace std;


vector<Student_info> extract_fails(vector<Student_info>& students);

int main()
{
  clock_t prog_begin = clock();
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;   // the length of the longest name

  // read and store all the students' data.
  while(read(cin, record)){
    // find the length of the longest name
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // extract failing students
  clock_t t_begin = clock();
  vector<Student_info> f_students = extract_fails(students);
  clock_t t_end = clock();
  double elapsed_secs = double(t_end - t_begin) / CLOCKS_PER_SEC;
  
  
  // write the names and grades
  cout << "\nPassing students: " << endl;
  vector<Student_info>::iterator iter = students.begin();
  while(iter != students.end()){
    // write the name, padded on the right to maxlen + 1 characters
    cout << iter->name
	 << string(maxlen + 1 - iter->name.size(), ' ');

    // compute and write the grade
    try{
      double final_grade = grade(*iter);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec);
    }catch (domain_error e) {
      cout << e.what();
    }
    
    cout << endl;
    ++iter;
  }
  
  cout << "\nFailing students: " << endl;
  iter = f_students.begin();
  while(iter != f_students.end()){
    // write the name, padded on the right to maxlen + 1 characters
    cout << iter->name
	 << string(maxlen + 1 - iter->name.size(), ' ');

    // compute and write the grade
    try{
      double final_grade = grade(*iter);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec);
    }catch (domain_error e) {
      cout << e.what();
    }
    
    cout << endl;
    ++iter;
  }
  
  clock_t prog_end = clock();
  double prog_elapsed = double(prog_end - prog_begin) / CLOCKS_PER_SEC;
  
  cout << "\nTotal number of students: " << students.size() + f_students.size() << endl;
  cout << "number of passing students: " << students.size() << endl;
  cout << "number of failing students: " << f_students.size() << endl;
  cout << "\ntime to extract failing students using vector: " << elapsed_secs << endl;
  cout << "total runtime using vector: " << prog_elapsed << endl;
 
  return 0;
}


vector<Student_info> extract_fails(vector<Student_info>& students)
{
  vector<Student_info> fail;
  vector<Student_info>::iterator iter = students.begin();
  while(iter != students.end()){
    if(fgrade(*iter)){
      fail.push_back(*iter);
      iter = students.erase(iter);
    }else{
      ++iter;
    }
  }
  
  return fail;
}
