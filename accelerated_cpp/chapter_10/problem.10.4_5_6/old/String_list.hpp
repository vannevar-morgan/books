#ifndef GUARD_string_list_h
#define GUARD_string_list_h


#include <string>
#include <cstddef> // for size_t

class String_list
{
  
public:
  typedef std::string* iterator;
  typedef const std::string* const_iterator;

  String_list(){ data_elements = 0; data = new std::string[init_size]; allocated_space = init_size;}
  ~String_list(){ delete[] data;}

  void push_back(const std::string& entry);
  std::string* erase(std::string* beg, std::string* end);
  void clear();
  size_t size(){ return data_elements;}
  iterator begin(){ return data;}
  iterator end(){ return data + data_elements;}

private:
  const static size_t init_size = 10;
  size_t allocated_space;
  size_t data_elements;
  std::string* data;
  
  void copy_data(const std::string* from, std::string* to);
};




#endif
