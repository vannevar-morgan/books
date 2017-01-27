#include "Str.hpp"
#include <memory> // for allocator
#include <algorithm> // for std::max()
#include <cstring> // for std::strlen()

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
  // set pointers
  Str_data = Str_avail = Str_allocated = 0;
}

void Str::create(const char* c)
{
  // allocate space
  // copy data
  // set pointers
  Str::size_type str_sz = std::strlen(c);
  Str_data = mem_allocator.allocate(str_sz);
  Str_allocated = Str_avail = std::uninitialized_copy(c, c + str_sz, Str_data);
}

void Str::create(Str::size_type n, const char& c)
{
  Str_data = mem_allocator.allocate(n);
  std::uninitialized_fill_n(Str_data, n, c);
  Str_allocated = Str_avail = Str_data + n;
}

void Str::create(Str::const_iterator b, Str::const_iterator e)
{
  Str_data = mem_allocator.allocate(e - b);
  Str_allocated = Str_avail = std::uninitialized_copy(b, e, Str_data);
}

void Str::uncreate()
{
  if(Str_data){
    // destroy each element in reverse order
    iterator it = Str_avail;
    while(it >= Str_data){
      mem_allocator.destroy(--it);
    }
    
    // deallocate the Str_data
    mem_allocator.deallocate(Str_data, Str_allocated - Str_data);
  }

  Str_data = Str_avail = Str_allocated = 0;
}

void Str::unchecked_append(Str::value_type c)
{
  mem_allocator.construct(Str_avail++, c);
}

void Str::grow()
{
  // Allocate new space, copy over the old data, destroy the old data, set pointers
  size_type new_size = std::max( (difference_type) 1, 2*(Str_allocated - Str_data) );
  iterator temp_data = mem_allocator.allocate(new_size);
  iterator temp_avail = std::uninitialized_copy(Str_data, Str_avail, temp_data);
  
  uncreate();
  
  Str_data = temp_data;
  Str_avail = temp_avail;
  Str_allocated = Str_data + new_size;
}


#include <cctype> // for isspace()
std::istream& operator>> (std::istream& is, Str& s)
{
  s.clear();

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

  return is;
}

std::ostream& operator<< (std::ostream& os, const Str& s)
{
  for(Str::const_iterator i = s.begin(); i != s.end(); ++i){
    os << *i;
  }
  return os;
}

Str operator+ (const Str& left, const Str& right)
{
  Str temp = left;
  return temp += right;
}

Str::const_iterator Str::c_str() const
{
  const_cast<Str*>(this)->Str_avail = '\0';
  return Str_data;
}
