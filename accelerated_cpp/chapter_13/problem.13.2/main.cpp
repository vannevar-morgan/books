// ************************************************************
//              Name:  vann
//          Filename:  main.cpp
//           Project:  Accelerated C++, Problem 13-2
//       
//      Date written:  November 29, 2015
//
// ************************************************************
#include "Core.hpp"
#include "Grad.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
  Core* p1 = new Core; // calls Core::Core()
  cout << endl;
  Core* p2 = new Grad; // calls Grad::Grad() which invokes Core::Core() (remember base class portion is constructed first, Core::Core() will run before the body of Grad::Grad())
  cout << endl;
  Core s1; // calls Core::Core()
  cout << endl;
  Grad s2; // calls Grad::Grad() which invokes Core::Core() (remember base class portion is constructed first, Core::Core() will run before the body of Grad::Grad())
  cout << "~~~~~" << endl;
  
  try{
    p1->grade(); // calls Core::grade()
  }catch (domain_error e){
  }
  p1->name(); // calls Core::name()
  cout << endl;
  
  try{
    p2->grade(); // calls Grad::grade() which invokes Core::grade()
  }catch (domain_error e){
  }
  p2->name(); // calls Core::name()
  cout << endl;
  
  try{
    s1.grade(); // calls Core::grade()
  }catch (domain_error e){
  }
  s1.name(); // calls Core::name()
  cout << endl;

  s2.name(); // calls Core::name()
  try{
    s2.grade(); // calls Grad::grade() which invokes Core::grade()
  }catch (domain_error e){
  }

  return 0;
}
