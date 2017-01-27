/*
 * Accepts two files as arguments to main.
 *
 * First file is input file.
 * Second file is output file.
 *
 * Copies data from the input file to the output file.
 *
 * Page 181, Section 10.5, Accelerated C++
 */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  if(argc != 3){
    std::cout << "usage: ./files input_file output_file" << std::endl;
    return -1;
  }

  std::ifstream input(argv[1]);
  if(!input){
    std::cout << "error creating input stream\n";
    return -1;
  }
  std::ofstream output(argv[2]);
  if(!output){
    std::cout << "error creating output stream\n";
    return -1;
  }

  std::string s;
  while(getline(input, s)){
    output << s << std::endl;
  }

  return 0;
}
