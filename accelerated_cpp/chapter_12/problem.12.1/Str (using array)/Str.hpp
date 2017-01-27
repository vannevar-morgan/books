#ifndef guard_str_hpp
#define guard_str_hpp

#include <algorithm> // for copy
#include <cstring> // strlen()
#include <iterator> // for back_inserter()
#include <istream> // for istream
#include <ostream> // for ostream
#include <cstddef> // for size_t, ptrdiff_t
#include <cstdlib> // for malloc

class Str
{
  friend std::istream& operator>>(std::istream&, Str&);
  
public:
  typedef size_t size_type;
  
  // default constructor: create an empty Str
  Str(): length(0), allocated_space(0), data(0) {}

  // create a Str containing n copies of c
  Str(size_type n, char c): length(n) { str_fill(n, c); }

  // copy constructor
  Str(const Str& s){
    length = s.length;
    data = allocate_str(length);
    str_copy(s.data, s.data + length, data);
  }

  // create a Str from a null-terminated array of char
  Str(const char* cp){
    data = allocate_str(std::strlen(cp));
    str_copy(cp, cp + std::strlen(cp), data);
    length = std::strlen(cp);
  }

  // create a Str from the range denoted by iterators b and e
  template <class In>
  Str(In b, In e){
    data = allocate_str(e - b);
    str_copy(b, e, data);
    length = e - b;
  }

  // destructor for Str class, needs to free the memory allocated for data
  ~Str() { free(data); }

  // assignment operator
  Str& operator=(const Str& s){
    // check for self assignment
    if(&s != this){
      free(data);
      length = s.length;
      allocate_str(length);
      str_copy(s.data, s.data + length, data);
    }
    return *this;
  }

  char& operator[](size_type i) { return *(data + i); }
  const char& operator[](size_type i) const { return *(data + i); }

  Str& operator+=(const Str& s) {
    size_type sz = this->length + s.size();
    grow_str(sz);
    str_copy(s.data, s.data + s.length, this->data + this->length);
    this->length = sz;
    return *this;
  }

  size_type size() const { return length; }

  void clear(){
    free(data);
    length = 0;
    allocated_space = 0;
  }


private:
  char* data;
  size_type length;
  size_type allocated_space;

  //  void str_copy(const char* b, const char* e, char* d);

  template <class In>
  void str_copy(In b, In e, char* d);  

  void grow_str(size_type sz);
  char* allocate_str(size_type sz);
  void str_fill(size_type n, char c);

};


template <class In>
void Str::str_copy(In b, In e, char* d)
{
  // d is assumed to point to space sufficient to hold the range (b, e]
  while(b < e){
    *d++ = *b++;
  }
}



std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str& left, const Str& right);

#endif

