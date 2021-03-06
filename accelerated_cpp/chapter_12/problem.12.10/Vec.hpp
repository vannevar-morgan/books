#ifndef vec_hpp
#define vec_hpp

#include <cstddef> // for size_t, ptrdiff_t
#include <memory> // for std::allocator<T>
#include <algorithm> // for std::max()

template <class T>
class Vec{

public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef T& reference;
  typedef const T& const_reference;

  Vec() { create(); }
  
  template <typename In>
  Vec(In b, In e) { create(b, e); }

  explicit Vec(size_type n, const T& t = T()) { create(n, t); }
  Vec(const Vec& v) { create(v.begin(), v.end()); }
  Vec& operator=(const Vec& rhs);
  ~Vec() { uncreate(); }

  T& operator[](size_type i) { return data[i]; }
  const T& operator[](size_type i) const { return data[i]; }

  void push_back(const T& val)
  {
    if(avail == limit){
      grow();
    }
    unchecked_append(val);
  }

  void clear()
  {
    uncreate();
  }

  bool empty() const { return !avail; }

  iterator erase(iterator first, iterator last = 0);

  size_type size() const { return avail - data; }

  iterator begin() { return data; }
  const_iterator begin() const { return data; }

  iterator end() { return avail; }
  const_iterator end() const { return avail; }

private:
  iterator data;
  iterator avail;
  iterator limit;
  
  std::allocator<T> alloc;
  void create();
  void create(size_type, const T&);
  void create(const_iterator b, const_iterator e);

  template <class In>
  void create(In b, In e);

  void uncreate();
  void grow();
  void unchecked_append(const T&);
  void destroy_range(iterator first, iterator last = 0);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
  if(&rhs != this){
    // free the array in the left-hand side
    uncreate();

    // copy elements from the right-hand side to the left-hand side
    create(rhs.begin(), rhs.end());
  }
  return *this;
}

template <class T>
void Vec<T>::create()
{
  data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
  data = alloc.allocate(n);
  limit = avail = data + n;
  std::uninitialized_fill(data, limit, val);
}


template <class T>
template <class In>
void Vec<T>::create(In b, In e)
{
  data = alloc.allocate(e - b);
  limit = avail = std::uninitialized_copy(b, e, data);
}


template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
  data = alloc.allocate(j - i);
  limit = avail = std::uninitialized_copy(i, j, data);
}



template <class T>
void Vec<T>::uncreate()
{
  if(data){
    iterator it = avail;
    while(it != data){
      alloc.destroy(--it);
    }

    alloc.deallocate(data, limit - data);
  }

  data = avail = limit = 0;
}

template <class T>
void Vec<T>::grow()
{
  size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = std::uninitialized_copy(data, avail, new_data);

  uncreate();

  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val)
{
  alloc.construct(avail++, val);
}

template <class T>
void Vec<T>::destroy_range(iterator first, iterator last)
{
  if(!last){
    last = first + 1;
  }
  
  while(first < last){
    alloc.destroy(--last);
  }
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator first, iterator last)
{
  if(!last){
    last = first + 1;
  }
  
  if(first >= data && last <= avail){
    ptrdiff_t range_sz = last - first;
    destroy_range(first, last);
    std::uninitialized_copy(last, avail, first);
    avail -= range_sz;
  }
  return first;
}



#endif
