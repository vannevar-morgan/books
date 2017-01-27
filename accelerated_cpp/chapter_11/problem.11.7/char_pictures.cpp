#include "Vec.hpp"
#include <string>
#include <iostream>
#include <algorithm> // for max();

using namespace std;

string::size_type get_max_width(const Vec<string>& picture);
Vec<string> frame(const Vec<string>& picture);
Vec<string> center(const Vec<string>& picture);
void print_picture(const Vec<string>& picture);

int main()
{
  Vec<string> picture;
  cout << "enter some words to frame in a character picture: " << endl;
  string n;
  while(getline(cin, n)){
    picture.push_back(n);
  }
  
  Vec<string> picture2 = frame(picture);
  Vec<string> picture3 = center(picture);

  print_picture(picture2);
  print_picture(picture3);

  return 0;
}

void print_picture(const Vec<string>& picture)
{
  // print character picture
  for(Vec<string>::size_type i = 0; i != picture.size(); ++i){
    cout << picture[i] << endl;
  }
  cout << endl;
}

string::size_type get_max_width(const Vec<string>& picture)
{
  string::size_type maxlen = 0;
  for(Vec<string>::size_type i = 0; i != picture.size(); ++i){
    maxlen = max(maxlen, picture[i].size());
  }
  return maxlen;
}

Vec<string> frame(const Vec<string>& picture)
{
  // example 5.8.1, pg 92
  Vec<string> ret;
  
  string::size_type max_width = get_max_width(picture);
  string border = string(max_width + 4, '*');
  ret.push_back(border);
  for(Vec<string>::size_type i = 0; i != picture.size(); ++i){
    string padding = string(max_width - picture[i].size(), ' ');
    string temp = "* " + picture[i] + padding + " *";
    ret.push_back(temp);
  }
  ret.push_back(border);
  
  return ret;
}

Vec<string> center(const Vec<string>& picture)
{
  // problem 5-5, page 100
  Vec<string> ret;
  string::size_type max_width = get_max_width(picture);
  string border = string(max_width + 4, '*');

  ret.push_back(border);
  for(Vec<string>::size_type i = 0; i != picture.size(); ++i){
    string::size_type left_width = (max_width - picture[i].size()) / 2;
    string::size_type right_width = max_width - picture[i].size() - left_width;
    string left_padding = string(left_width, ' ');
    string right_padding = string(right_width, ' ');
    string temp = "* " + left_padding + picture[i] + right_padding + " *";
    ret.push_back(temp);
  }
  ret.push_back(border);

  return ret;
}
