#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iterator>


using namespace std;

// true if the argument is whitespace, false otherwise.
bool space(char c){
  return isspace(c);
}

// false if the argument is whitespace, true otherwise.
bool not_space(char c){
  return !isspace(c);
}

vector<string> split(const string& str){
  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = str.begin();
  while(i != str.end()){
    // ignore leading blanks
    i = find_if(i, str.end(), not_space);

    // find end of next word
    iter j = find_if(i, str.end(), space);

    // copy the characters in [i, j)
    if(i != str.end()){
      ret.push_back(string(i, j));
    }
    i = j;
  }
  return ret;
}


template <class Out>
Out xref(istream& in, Out os, vector<string> find_words(const string&) = split){
  string line;
  int line_number = 0;
  map<string, vector<int> > ret;

  // read the next line
  while(getline(in, line)){
    ++line_number;

    // break the input line into words
    vector<string> words = find_words(line);

    // remember that each word occurs on the current line
    for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it){
      ret[*it].push_back(line_number);
    }
  }
  copy(ret.begin(), ret.end(), os);
  return os;
}


//
//
// To print to cout using ostream_iterator, we need to make
// an adapter class for ostream_iterator, then use that.
//
// Adapter class (modified slightly) from:
// http://www.drdobbs.com/cpp/an-enhanced-ostreamiterator/201200278
//
//
template< typename V
    , typename C = char
    , typename T = std::char_traits<C>
    , typename S = std::basic_string<C, T>
    >
class ostream_print_iterator
 : public std::iterator<std::output_iterator_tag
            , void, void, void, void>
{ 
public: // Member Types
 typedef V                      assigned_type;
 typedef C                      char_type;
 typedef T                      traits_type;
 typedef S                      string_type;
 typedef std::basic_ostream<char_type, traits_type> ostream_type;
 typedef ostream_print_iterator<V, C, T, S>        class_type;
public: // Construction
 explicit ostream_print_iterator(ostream_type& os)
  : m_stm(&os)
  , m_prefix()
  , m_suffix()
 { } 
 template <typename S1>
 explicit ostream_print_iterator(ostream_type& os, S1 const& suffix)
  : m_stm(&os)
  , m_prefix()
  , m_suffix(suffix)
 { } 
 template< typename S1
     , typename S2
     >
 ostream_print_iterator(ostream_type& os, S1 const& prefix, S2 const& suffix)
  : m_stm(&os)
  , m_prefix(prefix)
  , m_suffix(suffix)
 { } 
 ostream_print_iterator(class_type const& rhs)
  : m_stm(rhs.m_stm)
  , m_prefix(rhs.m_prefix)
  , m_suffix(rhs.m_suffix)
 { } 
 ~ostream_print_iterator() throw()
 { } 
public: // Assignment
 class_type& operator =(assigned_type const& value)
 { 
   *m_stm << m_prefix << value.first << " occurs on line(s): ";
   for(int i = 0; i < value.second.size(); ++i){
     *m_stm << value.second[i] << ", ";
   }
   *m_stm << "\b\b  " << m_suffix; // erase the trailing comma
   return *this;
 } 
public: // Output Iterator Methods
 class_type& operator *()
 { 
  return *this;
 } 
 class_type& operator ++()
 { 
  return *this;
 } 
 class_type operator ++(int)
 { 
  return *this;
 } 
private: // Member Variables
 ostream_type* m_stm;
 string_type  m_prefix;
 string_type  m_suffix;
} ;


int main(){
  bool test_with_cout = false; // toggle to switch between testing modes
  
  if(test_with_cout){
    //
    // Test by printing directly to cout using ostream_print_iterator.
    //
    // to print to cout with ostream_iterator, need to make an adapter class for ostream_iterator, then use that
    xref(cin, ostream_print_iterator<pair<string, vector<int> > >(cout, "\n"));
  }else{
    //
    // Test by inserting results into a map, and then printing.
    //
    map<string, vector<int> > ret;
    xref(cin, inserter(ret, ret.end()));

    // write the results
    for(map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it){
      // write the word
      cout << it->first << " occurs on line(s): ";

      // followed by one or more line numbers
      vector<int>::const_iterator line_it = it->second.begin();
      cout << *line_it; // write the first line number
      
      ++line_it;

      // write the rest of the line numbers, if any
      while(line_it != it->second.end()){
        cout << ", " << *line_it;
        ++line_it;
      }

      // write a new line to separate each word from the next.
      cout << endl;
    }
  }
    
  return 0;
}
