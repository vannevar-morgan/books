/*
 * Accepts filenames as arguments to main, prints the contents of each file to terminal
 *
 * Page 182, Section 10.5, Accelerated C++
 */
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  if(argc < 2){
    std::cout << "usage: ./fileprint file1 file2 ...\n" << std::endl;
    return -1;
  }

  int fail_count = 0;
  for(int i = 1; i < argc; ++i){
    std::ifstream input(argv[i]);
    if(input){
      std::cout << argv[i] << ": \n";
      std::string s;
      while(getline(input, s)){
	std::cout << s << std::endl;
      }
      std::cout << std::endl;
    }else{
      std::cout << "couldn't open file: " << argv[i] << std::endl;
      ++fail_count;
    }
  }

  std::cout << "Total files failed to open: " << fail_count << std::endl;

  return fail_count;
}
