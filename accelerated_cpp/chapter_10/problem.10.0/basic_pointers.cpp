/* Illustrates basic usage of pointers, uses a pointer to modify the value of an * object without refering to the object itself.
 *
 * Page 171, Section 10.1, Accelerated C++
 */

#include <iostream>


int main()
{
  int a = 10;
  int* b = &a;
  
  std::cout << "original value a: " << a << std::endl;

  *b += 10; // changed value of a through pointer b, value of a is now 20
  
  std::cout << "new value of a: " << a << std::endl;

  return 0;
}
