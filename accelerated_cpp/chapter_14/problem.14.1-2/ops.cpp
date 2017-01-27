#include "ops.hpp"
#include "Core.hpp"
#include "Ptr.hpp"
#include <istream>
#include <vector>
#include <stdexcept>

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
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

bool compare_Core_ptrs(const Ptr<Core>& student1, const Ptr<Core>& student2)
{
  if(!student1){
    throw std::runtime_error("comparison with an unknown student");
  }
  if(!student2){
    throw std::runtime_error("comparison with an unknown student");
  }

  return student1->name() < student2->name();
}
