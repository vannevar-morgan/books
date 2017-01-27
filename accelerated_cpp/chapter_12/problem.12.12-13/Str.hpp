#ifndef guard_Str_hpp
#define guard_Str_hpp

#include <memory> // for allocator
#include <cstddef> // for size_t, ptrdiff_t
#include <istream> // for std::istream
#include <ostream> // for std::ostream
#include <cstring> // for std::strlen()

class Str
{

  
public:
  typedef char* iterator;
  typedef const char* const_iterator;
  typedef size_t size_type;
  typedef char value_type;
  typedef ptrdiff_t difference_type;
  typedef char& reference;
  typedef const char& const_reference;

  Str() { create(); }

  Str(const char* c) { create(c); }
  
  Str(size_type n, const char& c) { create(n, c); }

  
  template <class In>
  Str(In b, In e) { create(b, e); }
  
  Str(const Str& s) { create(s.begin(), s.end()); }

  ~Str() { uncreate(); }

  Str& operator= (const Str& s);
  
  size_type size() const { return Str_avail - Str_data; }
  size_type length() const { return Str_avail - Str_data; }

  iterator begin() { return Str_data; }
  const_iterator begin() const { return Str_data; }
  iterator end() { return Str_avail; }
  const_iterator end() const { return Str_avail; }
  
  const_iterator cbegin() const { return Str_data; }
  const_iterator cend() const { return Str_avail; }
  
  void clear(){
    uncreate();
    Str_data = mem_allocator.allocate(1);
    Str_avail = Str_data;
    mem_allocator.construct(Str_data, '\0');
    Str_allocated = Str_data + 1;
  }

  bool empty() const { return Str_data == Str_avail; }
  
  char& operator[] (size_type i) { return Str_data[i]; }
  const char& operator[] (size_type i) const { return Str_data[i]; }

  Str& operator+= (const Str& s){
    for(const_iterator i = s.begin(); i != s.end(); ++i){
      this->push_back(*i);
    }
    return *this;
  }

  Str& operator+= (const char* s){
    size_type str_sz = std::strlen(s);
    for(size_type i = 0; i != str_sz; ++i){
      this->push_back(s[i]);
    }
    return *this;
  }

  const_iterator c_str() const { return Str_data; }
  const_iterator data() const { return Str_data; }
  size_type copy(iterator p, size_type n, size_type pos = 0) const;

  void push_back(const char& c){
    if(Str_avail == Str_allocated || Str_avail == Str_data){
      grow();
    }
    unchecked_append(c);
  }
  
  inline operator bool() const{
    return !(this->empty());
  }
  
  template <typename In>
  iterator insert(const_iterator pos, In b, In e);

private:
  iterator Str_data;
  iterator Str_avail;
  iterator Str_allocated;
  
  std::allocator<char> mem_allocator;
  
  void create();
  void create(const char* c);
  void create(size_type n, const char& c);
  void create(const_iterator b, const_iterator e);

  void uncreate();
  void unchecked_append(value_type c);
  void grow();

};

std::istream& operator>> (std::istream& is, Str& s);
std::ostream& operator<< (std::ostream& os, const Str& s);
Str operator+ (const Str& left, const Str& right);
Str operator+ (const Str& left, const char* right);
Str operator+ (const char* left, const Str& right);


bool operator> (const Str& left, const Str& right);
bool operator< (const Str& left, const Str& right);
bool operator<= (const Str& left, const Str& right);
bool operator>= (const Str& left, const Str& right);
bool operator== (const Str& left, const Str& right);
bool operator!= (const Str& left, const Str& right);

std::istream& getline(std::istream& is, Str& s, char delim = '\n');

template <typename In>
typename Str::iterator Str::insert(const_iterator pos, In b, In e)
{
  difference_type distance_to_insertion = pos - this->begin();
  
  // copy to temporary storage the data (pos, this->end]
  Str temp(pos, (const_iterator) this->end());
  
  // reset the avail pointer
  Str_avail = this->begin() + distance_to_insertion;
  
  // push_back() the data (b, e]
  while(b != e){
    this->push_back(*b++);
  }
  
  // push_back() the data from temporary storage
  for(Str::size_type i = 0; i < temp.size(); ++i){
    this->push_back(temp[i]);
  }
  
  return this->begin() + distance_to_insertion;  
}

#endif
