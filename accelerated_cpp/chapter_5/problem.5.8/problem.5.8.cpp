#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
vector<string> hcat(const vector<string>& left, const vector<string>& right);

int main()
{
  // get some text from user to frame
  cout << "enter some text to frame: " << endl;
  vector<string> text;
  string s;
  while(getline(cin, s)){
    text.push_back(s);
  }
  
  // use the framed text to test, framed text has two extra lines
  vector<string> framed_text = frame(text);
  
  // uncomment the following lines to test the case where the right picture is larger but the previous, current, and remaining lines are the empty string (you could add more empty strings and it would only duplicate the last line of the hcat text)
  // you need to input at least 1 line when running (so you have enough text lines to test with) or it will segfault.
  // framed_text[framed_text.size() - 1] = "";
  // framed_text[framed_text.size() - 2] = "";
  // framed_text[framed_text.size() - 3] = "";
  // framed_text.push_back("");
  // framed_text.push_back("");
  // framed_text.push_back("");

  // you can trigger the same error by uncommenting the following line:
  //  string s_length_error(-1, ' ');

  // make horizontally concatenated text
  vector<string> horizontal_text = hcat(text, framed_text); // right picture has 2 lines more than the left picture (error, except special condition)
  //  vector<string> horizontal_text = hcat(framed_text, text); // left picture has 2 lines more than the right picture (no error)
  
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


vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;
  
  // add 1 to leave a space between pictures
  string::size_type width1 = width(left) + 1;
  
  // indices to look at elements from left and right respectively
  vector<string>::size_type i = 0, j = 0;
  
  // continue until we've seen all rows from both pictures
  string s;
  while(i != left.size() || j != right.size()){
    // construct new string to hold characters from both pictures
    // string s;
    
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
