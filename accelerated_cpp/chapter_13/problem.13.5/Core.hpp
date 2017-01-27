#ifndef guard_core_hpp
#define guard_core_hpp

#include <istream>
#include <string>
#include <vector>
//#include <iostream>

class Core
{
  /*
   * November 25, 2015
   * 
   * Core is a class to represent undergrad students.  It contains member 
   * variable and functions common to both undergrad and grad students.
   */
  friend class Student_info;
  
public:
  Core(): midterm(0), final(0), n("") {}
  Core(std::istream& is): midterm(0), final(0), n("") { read(is); }
  virtual ~Core() {}
  
  std::string name() const;
  // added the isValid() function for problem 13.3, 
  // to check if a student object holds valid values for grading.
  bool isValid() const;
  virtual bool isMissingWork() const;
  
  virtual std::istream& read(std::istream& is);
  virtual double grade() const;

protected:
  virtual Core* clone() const { return new Core(*this); }
  
  std::istream& read_common(std::istream& is);
  double midterm, final;
  std::vector<double> homework;
  
private:
  std::string n;
  
};



#endif
