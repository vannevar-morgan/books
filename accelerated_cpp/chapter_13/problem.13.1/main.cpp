// ************************************************************
//              Name:  vann
//          Filename:  main.cpp
//           Project:  Accelerated C++, Problem 13-1
//       
//      Date written:  November 28, 2015
//
// ************************************************************
#include "Core.hpp"
#include "Grad.hpp"
#include <iostream>

using namespace std;

int main()
{
  // Output should match exactly as described in output_predictions.txt
  cout << "Making a Core object with default constructor..." << endl;
  Core uStudent;
  cout << endl << "Making a Core object with istream& constructor..." << endl;
  Core uStudent2(cin);
  cout << endl << "Making a Grad object with default constructor..." << endl;
  Grad gStudent;
  cout << endl << "Making a Grad object with istream& constructor..." << endl;
  Grad gStudent2(cin);
  return 0;
}
