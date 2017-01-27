#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
vector<string> vcat(const vector<string>& top, const vector<string>& bottom);
vector<string> hcat(const vector<string>& left, const vector<string>& right);
vector<string> center(const vector<string>& picture);

int main()
{
  // get some text from user to frame
  cout << "enter some text to frame: " << endl;
  vector<string> text;
  string s;
  while(getline(cin, s)){
    text.push_back(s);
  }

  // center the text
  vector<string> center_text = center(text);

  // print the centered text
  cout << endl;
  for(const string& s : center_text){
    cout << s << endl;
  }

  // frame the centered text
  center_text = frame(center_text);
  cout << endl;
  for(const string& s : center_text){
    cout << s << endl;
  }
  
  // frame the text
  vector<string> framed_text = frame(text);
  
  // print the framed text
  cout << endl;
  for(const string& s : framed_text){
    cout << s << endl;
  }
  
  // make vertically concatenated text
  vector<string> vertical_text = vcat(text, framed_text);
  
  // print vertically concatenated text
  cout << endl;
  for(const string& s : vertical_text){
    cout << s << endl;
  }
  
  // make horizontally concatenated text
  vector<string> horizontal_text = hcat(text, framed_text);
  
  // print horizontally concatenated text
  cout << endl;
  for(const string& s : horizontal_text){
    cout << s << endl;
  }


  return 0;
}


string::size_type width(const vector<string>& v)
{
  //
  // Return the length of the longest string in v
  //
  string::size_type maxlen = 0;
  for(vector<string>::size_type i = 0; i < v.size(); ++i){
    maxlen = max(maxlen, v[i].size());
  }
  return maxlen;
}


vector<string> center(const vector<string>& picture){
  //
  // Center the picture by padding all lines evenly on left and right
  // to match the length of the longest string in the picture.
  //
  string::size_type maxlen = width(picture);
  vector<string> center_picture(picture);
  for(vector<string>::size_type i = 0; i < center_picture.size(); ++i){
    string::size_type pad_length = maxlen - center_picture[i].size();
    string::size_type left_pad = pad_length / 2;
    center_picture[i] = string(left_pad, ' ') + center_picture[i] + string(pad_length - left_pad, ' ');
  }
  return center_picture;
}


vector<string> frame(const vector<string>& v)
{
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');
  
  // write the top border
  ret.push_back(border);
  
  // write each interior row, bordered by an asterisk and a space
  for(vector<string>::size_type i = 0; i < v.size(); ++i){
    ret.push_back("* " + v[i] + string(maxlen -v[i].size(), ' ') + " *");
  }
  
  // write the bottom border
  ret.push_back(border);
  return ret;
}


vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
  // copy the top picture
  vector<string> ret = top;
  
  // copy entire bottom picture
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  
  return ret;
}


vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;
  
  // add 1 to leave a space between pictures
  string::size_type width1 = width(left) + 1;
  
  // indices to look at elements from left and right respectively
  vector<string>::size_type i = 0, j = 0;
  
  // continue until we've seen all rows from both pictures
  while(i != left.size() || j != right.size()){
    // construct new string to hold characters from both pictures
    string s;
    
    // copy a row from the left-hand side, if there is one
    if(i != left.size()){
      s = left[i++];
    }
    
    // pad to full width
    s += string(width1 - s.size(), ' ');
 
    // copy a row from the right-hand side, if there is one
    if(j != right.size()){
      s += right[j++];
    }
    
    // add s to the picture we're creating
    ret.push_back(s);
  }
  
  return ret;
}
