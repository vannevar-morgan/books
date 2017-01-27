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
  //  friend class Ptr<Core>; // Ptr needs access to clone(), which is protected
  
public:
  Core(): midterm(0), final(0), n("") {}
  Core(std::istream& is): midterm(0), final(0), n("") { read(is); }
  virtual ~Core() {}
  
  std::string name() const;

  virtual std::istream& read(std::istream& is);
  virtual double grade() const;

  virtual Core* clone() const { return new Core(*this); } // clone() was moved to public instead of protected because the Ptr class needs to be able to call clone().  Otherwise you must grant friendship (so, Ptr would need class friendship from any class it's intended to be used with (which has clone() under protected access) which seems tedious and a bad design requirement to impose vs making clone public.  A better strategy would be to make clone a public pure virtual function in an interface implemented by any class that wishes to be clonable.).


protected:
  std::istream& read_common(std::istream& is);
  double midterm, final;
  std::vector<double> homework;
  
private:
  std::string n;
  
};



#endif
