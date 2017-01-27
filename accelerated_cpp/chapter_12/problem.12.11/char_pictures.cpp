#include "Str.hpp"
#include <vector>
#include <iostream>

using namespace std;

typedef vector<Str>::size_type vec_iter;

vector<Str> frame(const vector<Str>& pic);
vector<Str> center(const vector<Str>& pic);
Str::size_type getMaxWidth(const vector<Str>& pic);
void print_picture(const vector<Str>& pic);

int main()
{
  // get some input to frame
  cout << "enter some text: " << endl;
  Str s;
  vector<Str> words;
  while(cin >> s){
    words.push_back(s);
  }
  cin.clear();

  vector<Str> framed_words = frame(words);
  print_picture(framed_words);

  vector<Str> centered_words = center(words);
  print_picture(centered_words);
    
  return 0;
}

void print_picture(const vector<Str>& pic)
{
  /*
   * Prints a character picture to the standard output.
   * The character picture consists of a vector of strings.
   */
  for(vec_iter i = 0; i < pic.size(); ++i){
    cout << pic[i] << endl;
  }
}

vector<Str> frame(const vector<Str>& pic)
{
  /*
   * frame() function from page 93, Section 5.8.1
   *
   * frames a character picture with "*"
   */
  Str::size_type width = getMaxWidth(pic);
  vector<Str> framed_pic;
  Str border(width + 4, '*');
  framed_pic.push_back(border);
  for(vec_iter i = 0; i < pic.size(); ++i){
    Str padded = "* " + pic[i] + Str(width - pic[i].size(), ' ') + " *";
    framed_pic.push_back(padded);
  }
  framed_pic.push_back(border);
  
  return framed_pic;
}

Str::size_type getMaxWidth(const vector<Str>& pic)
{
  /*
   * width() function from page 92, Section 5.8.1
   *
   * returns the size of the longest string in a vector of strings
   */
  Str::size_type maxWidth = 0;
  for(vec_iter i = 0; i < pic.size(); ++i){
    if(pic[i].size() > maxWidth){
      maxWidth = pic[i].size();
    }
  }
  
  return maxWidth;
}

vector<Str> center(const vector<Str>& pic)
{
  /*
   * Problem 5-5, page 100
   *
   * Returns a framed character picture with the characters centered in the picture.
   * The picture is represented as a vector of strings.
   */
  vector<Str> centered_pic;
  Str::size_type width = getMaxWidth(pic);
  Str border(width + 4, '*');
  centered_pic.push_back(border);

  for(vec_iter i = 0; i < pic.size(); ++i){
    Str::size_type left_padding = (width - pic[i].size()) / 2;
    Str::size_type right_padding = width - pic[i].size() - left_padding;
    Str padded = "* " + Str(left_padding, ' ') + pic[i] + Str(right_padding, ' ') + " *";
    centered_pic.push_back(padded);
  }
  centered_pic.push_back(border);

  return centered_pic;
}
