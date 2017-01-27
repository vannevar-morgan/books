#ifndef guard_str_hpp
#define guard_str_hpp

#include "Vec.hpp" // for Vec<>
#include "Ptr.hpp" // for Ptr<>
#include <cstring> // strlen()
#include <iterator> // for back_inserter()
#include <istream> // for istream
#include <ostream> // for ostream
#include <algorithm> // for copy

class Str
{
  friend std::istream& operator>>(std::istream&, Str&);
  
public:
  typedef Vec<char>::size_type size_type;
  typedef Vec<char>::iterator iterator;
  typedef Vec<char>::const_iterator const_iterator;
  typedef Vec<char>::value_type value_type;
  typedef Vec<char>::difference_type difference_type;
  typedef Vec<char>::reference reference;
  typedef Vec<char>::const_reference const_reference;
  
  // default constructor: create an empty Str
  Str(): data(new Vec<value_type>) {}

  // create a Str containing n copies of c
  Str(size_type n, value_type c): data(new Vec<value_type>(n, c)) {}

  // create a Str from a null-terminated array of char
  Str(const_iterator cp): data(new Vec<value_type>){
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
  }

  // create a Str from the range denoted by iterators b and e
  template <class In>
  Str(In b, In e): data(new Vec<value_type>){
    std::copy(b, e, std::back_inserter(*data));
  }

  size_type size() const { return data->size(); }
  size_type length() const { return data->size(); }

  iterator begin() {
    data.make_unique();
    return data->begin(); 
  }
  
  const_iterator begin() const { return data->begin(); }
  
  iterator end() {
    data.make_unique();
    return data->end(); 
  }
  
  const_iterator end() const { return data->end(); }
  
  const_iterator cbegin() const { return data->begin(); }
  const_iterator cend() const { return data->end(); }

  void clear(){
    data.make_unique();
    data->clear();
  }

  bool empty() const { return data->empty(); }

  reference operator[](size_type i){
    data.make_unique();
    return (*data)[i];
  }

  const_reference operator[](size_type i) const { return (*data)[i]; }

  Str& operator+=(const Str& s) {
    data.make_unique();
    std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
    return *this;
  }

  Str& operator+= (const_iterator s){
    data.make_unique();
    size_type str_sz = std::strlen(s);
    for(size_type i = 0; i != str_sz; ++i){
      data->push_back(s[i]);
    }
    return *this;
  }

//////////////////////////////////////////////////
//////////////////////////////////////////////////
// c_str() is not currently implemented because //
// I see no simple way of ensuring the Str is   //
// always null terminated (Because memory       //
// management is delegated to Vec).             //
//////////////////////////////////////////////////
//////////////////////////////////////////////////

  // const_iterator c_str() const { return data->begin(); }
  // const_iterator data() const { return data->begin(); }
  // size_type copy(iterator p, size_type n, size_type pos = 0) const;

  inline operator bool() const{
    return !(this->empty());
  }



private:
  Ptr<Vec<char> > data;

};


std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+ (const Str& left, const Str& right);
Str operator+ (const Str& left, const char* right);
Str operator+ (const char* left, const Str& right);


//////////////////////////////////////////////
//////////////////////////////////////////////
// The following functions rely on c_str(). //
// Commented out because c_str is not       //
// currently implemented.                   //
//////////////////////////////////////////////
//////////////////////////////////////////////

// bool operator> (const Str& left, const Str& right);
// bool operator< (const Str& left, const Str& right);
// bool operator<= (const Str& left, const Str& right);
// bool operator>= (const Str& left, const Str& right);
// bool operator== (const Str& left, const Str& right);
// bool operator!= (const Str& left, const Str& right);

std::istream& getline(std::istream& is, Str& s, char delim = '\n');





#endif
