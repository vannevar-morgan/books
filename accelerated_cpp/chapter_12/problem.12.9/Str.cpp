#include "Str.hpp"
#include <memory> // for allocator
#include <algorithm> // for std::max(), std::copy()
#include <cstring> // for std::strlen()
#include <stdexcept> // for out_of_range exception
#include <cstring> // for std::strcmp()
#include <istream> // for std::istream()
#include <iterator> // for std::ostream_iterator<>
#include <iostream>
#include <ios>

Str& Str::operator= (const Str& s)
{
  if(&s != this){
    uncreate();
    create(s.begin(), s.end());
  }
  return *this;
}

void Str::create()
{
  Str_data =  mem_allocator.allocate(1);
  mem_allocator.construct(Str_data, '\0');
  Str_allocated = Str_avail = Str_data + 1;
}

void Str::create(const char* c)
{
  // allocate space
  // copy data
  // set pointers
  Str::size_type str_sz = std::strlen(c);
  Str_data = mem_allocator.allocate(str_sz + 1); // add 1 for the null character
  Str_avail = std::uninitialized_copy(c, c + str_sz, Str_data);
  mem_allocator.construct(Str_avail, '\0');
  Str_allocated = Str_avail + 1; // add 1 for the null character
}

void Str::create(Str::size_type n, const char& c)
{
  Str_data = mem_allocator.allocate(n + 1); // add 1 for the null character
  std::uninitialized_fill_n(Str_data, n, c);
  Str_avail = Str_data + n;
  mem_allocator.construct(Str_avail, '\0'); // append the null character
  Str_allocated = Str_avail + 1;
}

void Str::create(Str::const_iterator b, Str::const_iterator e)
{
  Str_data = mem_allocator.allocate(e - b + 1); // add 1 for the null character
  Str_avail = std::uninitialized_copy(b, e, Str_data);
  Str_allocated = Str_avail + 1;

  mem_allocator.construct(Str_avail, '\0'); // append the null character
}

void Str::uncreate()
{
  if(Str_data){
    // destroy each element in reverse order
    iterator it = Str_avail + 1; // add 1 because we need to destroy the null character also.
    while(it >= Str_data){
      mem_allocator.destroy(--it);
    }
    // deallocate the Str_data
    mem_allocator.deallocate(Str_data, Str_allocated - Str_data);
  }
  Str_data = Str_avail = Str_allocated = 0;
  // we do not set the null character until there is data in the string (consider if allocating 1 for the null character, and uncreate is called by the destructor)
}

void Str::unchecked_append(Str::value_type c)
{
  // It is assumed there is sufficient space allocated to append c.  Before calling unchecked_append(), call grow() if Str_avail == Str_allocated
  // maybe add an assertion...
  mem_allocator.construct(Str_avail++, c);
  mem_allocator.construct(Str_avail, '\0');
}

void Str::grow()
{
  // Allocate new space, copy over the old data, destroy the old data, set pointers
  size_type new_size = std::max( (difference_type) 1, 2*(Str_allocated - Str_data));
  iterator temp_data = mem_allocator.allocate(new_size);
  iterator temp_avail = std::uninitialized_copy(Str_data, Str_avail, temp_data);
  
  uncreate();
  
  Str_data = temp_data;
  Str_avail = temp_avail;
  Str_allocated = Str_data + new_size;

  mem_allocator.construct(Str_avail, '\0'); // append the null character to the end of the string
}


#include <cctype> // for isspace()
std::istream& operator>> (std::istream& is, Str& s)
{
  // This doesn't work because istream_iterator<T> is 
  // an input iterator - forward read access only.  The 
  // actual read operation occurs when the iterator is 
  // incremented - not when it is dereferenced.  This 
  // means once an object is read from the stream I can't
  // put it back on the stream.  There's no way to look 
  // forward on the stream because the object is only 
  // read when the iterator is incremented - if trying to 
  // dereference ahead of the current position it will 
  // return the last object read.
  
  s.clear();
  is >> std::noskipws;
  std::istream_iterator<char> input_it(is);
  std::istream_iterator<char> eos;

  while(input_it != eos && isspace(*input_it++)){ std::cout << "operator>>: reading space..." << std::endl; }
  while(input_it != eos && !isspace(*input_it)){
    s.push_back(*input_it);
    std::cout << "operator>>: read character " << *input_it++ << std::endl;
  }

  /*
  char c;
  while(is.get(c) && isspace(c)){}

  if(is){
    do{
      s.push_back(c);
    }while(is.get(c) && !isspace(c));
    
    if(is){
      is.unget();
    }
  }
  */

  return is;
}

std::ostream& operator<< (std::ostream& os, const Str& s)
{
  // Replaced with std::ostream_iterator<> as per Problem 12.9
  /*
  for(Str::const_iterator i = s.begin(); i != s.end(); ++i){
    os << *i;
  }
  return os;
  */
  std::ostream_iterator<char> out_it(os);
  std::copy(s.begin(), s.end(), out_it);
  return os;
}

Str operator+ (const Str& left, const Str& right)
{
  Str temp = left;
  return temp += right;
}

Str operator+ (const Str& left, const char* right)
{
  Str temp = left;
  return temp += right;
}

Str operator+ (const char* left, const Str& right)
{
  Str temp;
  Str::size_type str_sz = std::strlen(left);
  for(Str::size_type i = 0; i != str_sz; ++i){
    temp.push_back(left[i]);
  }
  return temp += right;
}

Str::size_type Str::copy(Str::iterator p, Str::size_type n, Str::size_type pos) const
{
  // p is a Str::iterator that is assumed to point to space sufficient to hold the n characters copied over from the underlying Str data.

  if(pos > this->size()){
    throw std::out_of_range("tried to copy data starting from a position outside the range of the Str data...");
  }
  
  // calculate the number of characters that can actually be copied over without exceeding the size of the Str
  Str::size_type copy_sz = pos + n <= this->size() ? n : (this->size() - pos);
  //std::cout << "necessary to copy " << copy_sz << " characters..." << std::endl;
  //std::cout << "pos: " << pos << std::endl;
  // copy the data to destination p
  /*
  for(Str::size_type i = 0; i < copy_sz; ++i){
    *p++ = *(Str_data + pos + i);
  }
  */
  std::copy(this->begin() + pos, this->begin() + pos + copy_sz, p);

  return copy_sz;
}


bool operator< (const Str& left, const Str& right)
{
  if( std::strcmp(left.c_str(), right.c_str()) < 0 ){
    return true;
  }
  return false;
}

bool operator> (const Str& left, const Str& right)
{
  if( std::strcmp(left.c_str(), right.c_str()) > 0 ){
    return true;
  }
  return false;
}

bool operator<= (const Str& left, const Str& right)
{
  if( !(std::strcmp(left.c_str(), right.c_str()) > 0) ){
    return true;
  }
  return false;
}

bool operator>= (const Str& left, const Str& right)
{
  if( !(std::strcmp(left.c_str(), right.c_str()) < 0) ){
    return true;
  }
  return false;
}

bool operator== (const Str& left, const Str& right)
{
  return !std::strcmp(left.c_str(), right.c_str());
}

bool operator!= (const Str& left, const Str& right)
{
  return std::strcmp(left.c_str(), right.c_str());
}

std::istream& getline(std::istream& is, Str& s, char delim)
{
  s.clear();
  char c;
  while(is.get(c) && c != delim){
    s.push_back(c);
  }
  return is;
}
