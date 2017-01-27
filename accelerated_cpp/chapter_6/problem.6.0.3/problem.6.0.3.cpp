/*
 * Accelerated C++, Problem 6.0, Pg. 105, Parsing URLs
 */

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "urls.hpp"




std::string get_text(const std::string& filename)
{
  std::string ret = "";
  std::string line;
  std::ifstream myfile (filename.c_str());
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      ret = ret + line;
      std::cout << line << std::endl;
    }
    myfile.close();
  } else {
    std::cout << "Unable to open file"; 
  }
  return ret;
}

void print_urls(const std::vector<std::string>& urls)
{
  if(urls.size() == 0){
    std::cout << "\nNo urls found..." << std::endl;
  }else{
    std::vector<std::string>::const_iterator beg = urls.begin();
    std::vector<std::string>::const_iterator end = urls.end();
    std::cout << std::endl << "Found urls: " << std::endl;
    while (beg != end) {
      std::cout << *beg << std::endl;
      ++beg;
    }
  }
  return;
}

int main(int argc, char** argv)
{
  if(argc != 2){
    std::cout << "usage: ./urls html_filename" << std::endl;
    return -1;
  }
  std::string web_filename = argv[1];
  std::string web_text = get_text(web_filename);
  std::vector<std::string> urls = find_urls(web_text);
  print_urls(urls);
  return 0;
}
