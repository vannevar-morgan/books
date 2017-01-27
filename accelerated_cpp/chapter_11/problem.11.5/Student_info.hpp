#ifndef student_info_guard
#define student_info_guard

#include <vector>
#include <string>
#include <iostream>
#include <istream>

class Student_info
{
public:
  Student_info(): midterm(0), final(0) { 
    created++; 
    std::cout << "\tconstructor executed..." << std::endl;
  }
  Student_info(std::istream& is) { 
    read(is); 
    created++;
    std::cout << "\t\tconstructor executed..." << std::endl;
  }

  Student_info(const Student_info& s)
  {
    n = s.name();
    midterm = s.get_midterm();
    final = s.get_final();
    homework = s.get_homework();
    copied++;
    std::cout << "\tcopy constructor executed..." << std::endl;
  }

  ~Student_info() { 
    destroyed++; 
    std::cout << "\tdestructor executed..." << std::endl;
  }

  Student_info& operator=(const Student_info& s)
  {
    // check for self-assignment
    if(&s != this){
      n = s.name();
      midterm = s.get_midterm();
      final = s.get_final();
      homework = s.get_homework();
    }
    assigned++;
    std::cout << "\tassignment operator executed..." << std::endl;
    return *this;
  }

  std::string name() const { return n; }
  bool valid() const { return !homework.empty(); }

  std::istream& read(std::istream&);
  double grade() const;
  
  double get_midterm() const { return midterm; }
  double get_final() const { return final; }
  std::vector<double> get_homework() const { return homework; }

  int get_created() const { return created; }
  int get_copied() const { return copied; }
  int get_assigned() const { return assigned; }
  int get_destroyed() const { return destroyed; }

private:
  std::string n;
  double midterm;
  double final;
  std::vector<double> homework;
  static int created;
  static int copied;
  static int assigned;
  static int destroyed;
  
};

bool compare(const Student_info&, const Student_info&);

#endif
