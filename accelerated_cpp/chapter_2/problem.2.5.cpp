/* $2.e/34
   Problem 2-5
   This program prints a set of "*" characters to form a square, a rectangle, and a triangle.
*/

#include <iostream>
#include <string>
using std::string;

int main()
{
  string line = "";

  std::cout << "How tall should the shape be?: ";
  int height;
  std::cin >> height;

  std::cout << std::endl;
  // print a square
  for (int i = 0; i < height; ++i){
    if (i == 0 || i == height-1){
      line.assign(height * 2, '*');
    }else{
      line.assign(height * 2 - 2, ' ');
      line = "*" + line + "*";
    }

    std::cout << line << "\n";
    line.clear();
  }

  std::cout << std::endl;
  // print a rectangle double the width of the square
  for (int i = 0; i < height; ++i){
    if (i == 0 || i == height-1){
      line.assign(height * 4, '*');
    }else{
      line.assign(height * 4 - 2, ' ');
      line = "*" + line + "*";
    }

    std::cout << line << "\n";
    line.clear();
  }

  std::cout << std::endl;
  // print a triangle the same height as the square
  for (int i = 0; i < height; ++i){
    if (i == 0){
      line.assign(height, ' ');
      line = line + "*" + line;
    }else if (i == height - 1){
      line.assign(height*2 + 1, '*');
    }else{
      line.assign(height, ' ');
      line.replace(i,1,"*");
      line = string(line.rbegin(), line.rend()) + " " + line;
    }

    std::cout << line << "\n";
    line.clear();
  }

  return 0;
}
