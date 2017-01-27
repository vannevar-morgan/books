/*
 * Example of returning an invalid pointer.
 *
 * Example usage of a static pointer and using dynamic memory management to return a dynamic pointer.
 *
 * Page 183, Section 10.6, Accelerated C++
 */

#include <iostream>


int* invalid_pointer();
int* pointer_to_static();
int* pointer_to_dynamic();

int main()
{
  std::cout << "x's value using the invalid pointer" << std::endl;
  int* inv_p = invalid_pointer();
  std::cout << *inv_p << std::endl;

  std::cout << "x's value using static pointer: " << *pointer_to_static() << std::endl;
  int* x = pointer_to_dynamic();
  std::cout << "x's value using dynamic pointer: " << *x << std::endl;
  
  delete x; // don't forget to free dynamically allocated memory when finished using it.

  return 0;
}

int* invalid_pointer()
{
  int x = 209;
  return &x; // x is deallocated when the function returns so the pointer is invalid
}

int* pointer_to_static()
{
  static int x = -88; // since x is defined as static it does not deallocate until the program ends.
  return &x;
}

int* pointer_to_dynamic()
{
  //  int x = new int(5);
  return new int(5); // int object is allocated dynamically so the pointer remains valid when the function returns.  But we need to remember to free the object at an appropriate later time.
}
