#include <iostream>
#include <algorithm>
#include "Student_info.hpp"
#include "Vec.hpp"
#include "Str.hpp"
#include "Picture.hpp"


using namespace std;

Picture histogram(const Vec<Student_info>& students);

int main(){
  Vec<Student_info> students;
  Student_info s;

  // read the names and grades
  while(s.read(cin)){
    students.push_back(s);
  }

  // put the students in alphabetical order
  sort(students.begin(), students.end(), Student_info::compare);

  // write the names and histograms
  cout << frame(histogram(students)) << endl;

  return 0;
}


Picture histogram(const Vec<Student_info>& students){
  Picture names;
  Picture grades;

  for(auto& s : students){
    names = vcat(names, Vec<Str>(1, s.name()));
    grades = vcat(grades, Vec<Str>(1, " " + Str(s.grade() / 5, '=')));
  }

  return hcat(names, grades);
}
