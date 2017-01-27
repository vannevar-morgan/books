#ifndef GUARD_template_defs
#define GUARD_template_defs

#include <algorithm>
// Template implementing the STL "replace" algorithm.  Demonstrates sequential read write access (forward iterator).
template <class For, class X> 
void new_replace(For beg, For end, const X& x, const X& y)
{
  while (beg != end)
    {
      if (*beg == x)
	{
	  *beg = y;
	}
      ++beg;
    }
}

// Template implementing the STL "reverse" algorithm.  Demonstrates bidirectional sequential read write access (bidirectional iterator).
template <class Bi>
void new_reverse(Bi begin, Bi end)
{
  while (begin != end)
    {
      --end;
      if (begin != end)
	{
	  std::swap(*begin++, *end);
	}
    }
}


#endif
