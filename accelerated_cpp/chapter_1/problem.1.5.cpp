#include <iostream>
#include <string>

int main()
{
  { std::string s = "a string";
    { std::string x = s + ", really";
      std::cout << s << std::endl;} // will fail to compile because of scope.
    std::cout << x << std::endl;    // check the scope of x. fix it and then it will compile.
  }
  
  return 0;
}


//
// Program won't compile because I'm referring to x outside the scope of x.
// 
// Program will compile if x is printed in the same block where it is defined, i.e.,
//
// #include <iostream>
// #include <string>

// int main()
// {
//   { std::string s = "a string";
//     { std::string x = s + ", really";
//       std::cout << s << std::endl;
//       std::cout << x << std::endl;}
//   }
  
//   return 0;
// }
//
// When compiled it will print:
// "a string"
// "a string, really"
