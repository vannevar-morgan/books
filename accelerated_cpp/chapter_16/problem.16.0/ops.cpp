#include <istream>
//#include <vector>
#include "ops.hpp"
#include "Vec.hpp"


std::istream& read_hw(std::istream& in, Vec<double>& hw)
{
  if(in){
    hw.clear();

    double x;
    while(in >> x){
      hw.push_back(x);
    }
    in.clear();
  }
  return in;
}
