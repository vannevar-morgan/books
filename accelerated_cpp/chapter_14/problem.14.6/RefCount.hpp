#ifndef guard_refcount_hpp
#define guard_refcount_hpp

#include <cstddef>
#include "Ptr.hpp"


class RefCount{
  template<class T>
  friend class Ptr;

public:
  RefCount(): count(1) {}


protected:
  inline bool is_unique() const { return count == 1; }

  inline operator bool() const { return count > 0; }

  inline void subscribe(){ ++count; }
  
  inline void unsubscribe(){ --count; }


private:
  std::size_t count;

};




#endif
