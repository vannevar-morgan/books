#include "Str.hpp" // for Str
#include <istream> // for istream
#include <ostream> // for ostream
#include <cctype> // for isspace()
#include <cstdlib> // for malloc
#include <iostream>


/*
void Str::str_copy(const char* b, const char* e, char* d)
{
  // d is assumed to point to space sufficient to hold the range (b, e]
  while(b < e){
    *d++ = *b++;
  }
}
*/

char* Str::allocate_str(size_type sz)
{
  // will allocate space of type char* sufficient to hold sz number of chars
  allocated_space = sz;
  return (char*) malloc(sz);
}

void Str::grow_str(size_type sz)
{
  // will allocate space sufficient to hold sz number of chars, 
  // will then copy over current data to that space, 
  // will then free the current data and point data to the newly allocated space
  // what if sz >= length?
  if(sz > length){
    char* temp = Str::allocate_str(sz);
    Str::str_copy(data, data + length, temp);
    if(length){
      free(data);
    }
    data = temp;
  }
}

void Str::str_fill(size_type n, char c)
{
  // will allocate space sufficient to hold n chars
  // will then fill the space with char c
  data = Str::allocate_str(n);
  for(size_type i = 0; i < n; ++i){
    data[i] = c;
  }
}



std::istream& operator>>(std::istream& is, Str& s)
{
  s.clear();
  
  char c;
  while(is.get(c) && isspace(c)){}

  if(is){
    Str::size_type sz = 0;
    do{
      s.grow_str(++sz);
      s.str_copy(&c, &c + 1, s.data + sz - 1);
      s.length = sz;
    } while(is.get(c) && !isspace(c));
    
    // put back the character at the end if it wasn't eof
    if(is){
      is.unget();
    }
  }

  return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
  for(Str::size_type i = 0; i != s.size(); ++i){
    os << s[i];
  }
  return os;
}

Str operator+(const Str& left, const Str& right)
{
  Str temp_str = left;
  temp_str += right;
  return temp_str;
}
