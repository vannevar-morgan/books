#include <iostream>
int main()  {{{{{{std::cout << "hello world" << std::endl;}}}}}}

//
// Program is valid.  Extra braces are still balanced and only have the effect of moving the scope of std::cout... to a deeper level (which in this case doesn't matter since it's the only statement).
//
