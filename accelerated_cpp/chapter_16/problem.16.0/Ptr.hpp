#ifndef guard_ptr_hpp
#define guard_ptr_hpp


#include "RefCount.hpp"
#include "Vec.hpp"
#include <stdexcept>


template <class T>
class Ptr{
public:
  // new member to copy the object conditionally when needed
  void make_unique(){
    if(!refptr->is_unique()){
      refptr->unsubscribe();
      refptr = new RefCount();
      p = p ? clone(p) : nullptr;
    }
  }

  // the rest of the class looks like Ref_handle except for its name
  Ptr() : p(nullptr), refptr(new RefCount()) {}
  Ptr(T* t) : p(t), refptr(new RefCount()) {}
  Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) { refptr->subscribe(); }

  Ptr& operator= (const Ptr&);

  ~Ptr();

  operator bool() const { return p; }

  T& operator* () const{
    if(p){
      return *p;
    }
    throw std::runtime_error("unbound Ptr");
  }

  T* operator-> () const{
    if(p){
      return p;
    }
    throw std::runtime_error("unbound Ptr");
  }


private:
  T* p;
  RefCount* refptr;

};


template <class T>
Ptr<T>& Ptr<T>::operator= (const Ptr& rhs){
  rhs.refptr->subscribe();
  refptr->unsubscribe();
  if(!*refptr){
    delete refptr;
    delete p;
  }
  refptr = rhs.refptr;
  p = rhs.p;
  return *this;
}


template <class T>
Ptr<T>::~Ptr(){
  if(refptr->is_unique()){
    delete refptr;
    delete p;
  }
}


template <class T>
T* clone(const T* tp){
  return tp->clone();
}

template <> Vec<char>* clone(const Vec<char>* vp);


#endif
