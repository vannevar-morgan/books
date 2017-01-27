#include <iostream>

int main(){
  int k = 0;
  while(k != 10){
    using std::cout;      // defines cout as a synonym for std::cout
    cout << "*";
    ++k;
  }
  std::cout << std::endl; // we must use the fully qualified std::cout here because we aren't in the scope of the while loop where the using statement has defined cout as a synonym for std::cout.
  return 0;
}
