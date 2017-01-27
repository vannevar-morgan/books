#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "Handle.hpp"
#include "Core.hpp"
#include "Grad.hpp"
#include "ops.hpp"

using namespace std;



int main()
{
  vector< Handle<Core> > students;
  Handle<Core> record;
  char ch;
  string::size_type maxlen = 0;
  
  // read and store the data
  while(cin >> ch){
    if(ch == 'U'){
      record = new Core;
    }else{
      record = new Grad;
    }
    record->read(cin);
    maxlen = max(maxlen, record->name().size());
    students.push_back(record);
  }
  
  // sort the students using the compare function that works with core handles
  sort(students.begin(), students.end(), compare_Core_handles);
  
  // write the names and grades
  for(vector< Handle<Core> >::size_type i = 0; i != students.size(); ++i){
    cout << students[i]->name()
	 << string(maxlen + 1 - students[i]->name().size(), ' ');
    try{
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec) << endl;
    }catch (domain_error e){
      cout << e.what() << endl;
    }
  }
  return 0;
}
