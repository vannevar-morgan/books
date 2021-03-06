// ************************************************************
//              Name:  vann
//          Filename:  main.cpp
//           Project:  Accelerated C++, Problem 13-3
//       
//      Date written:  December 5, 2015
//
// ************************************************************
#include "Student_info.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;
  
  while(record.read(cin)){
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }
  
  sort(students.begin(), students.end(), Student_info::compare);
  
  for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){
    if(students[i].isValid()){
      cout << students[i].name()
	   << string(maxlen + 1 - students[i].name().size(), ' ');
      try{
	double final_grade = students[i].grade();
	cout << students[i].letter_grade(final_grade) << endl;
      }catch (domain_error e){
	cout << e.what() << endl;
      }
    }else{
      cout << "detected an invalid student record... was the student initialized? did the student do any homework?" << endl;
    }
  }

  for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){
    if(students[i].isMissingWork()){
      cout << students[i].name() << " is missing work :(" << endl;
    }
  }
  return 0;
}
