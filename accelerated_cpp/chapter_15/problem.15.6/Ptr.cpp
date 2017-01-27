#include "Ptr.hpp"
#include "Vec.hpp"


// template <class T>
// T* clone(const T* tp){
//   return tp->clone();
// }


template <>
Vec<char>* clone(const Vec<char>* vp){
  return new Vec<char>(*vp);
}
