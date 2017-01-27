#include "String_list.hpp"
#include <string>
#include <cstddef> // for size_t
#include <stdexcept> // for std::domain_error

void String_list::push_back(const std::string& entry)
{
  if(allocated_space == data_elements + 1){
    // reallocate with more space and copy over current elements
    std::string* temp = data;
    allocated_space *= 3;
    data = new std::string[allocated_space];
    String_list::copy_data(temp, data);
    delete[] temp;
  }
  data[data_elements] = entry;
  ++data_elements;
}

void String_list::copy_data(const std::string* from, std::string* to)
{
  for(size_t i = 0; i < data_elements; ++i){
    to[i] = from[i];
  }
}

std::string* String_list::erase(std::string* beg_range, std::string* end_range)
{
  size_t range = end_range - beg_range;
  if(range > data_elements + 1){
    throw std::domain_error("iterators used for erase() are not valid...");
  }
  if(end_range > String_list::end()){
    throw std::domain_error("\"end\" iterator used for erase() is not a valid iterator...");
  }
  std::string* temp = beg_range;
  for(; beg_range < end_range; ++beg_range){
    *beg_range = ""; // doesn't actually invalidate the pointer
    --data_elements;
  }
  std::string* temp2 = temp;
  for(; beg_range < end_range; ++beg_range){
    *temp2++ = *beg_range;
  }
  return temp;
}


void String_list::clear()
{
  delete[] data;
  data_elements = 0;
  allocated_space = init_size;
  data = new std::string[init_size];
}
