#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iterator>
#include <utility>


using namespace std;


bool comp_wc_pairs(const pair<string, int>& wc1, const pair<string, int>& wc2){
  return wc1.second < wc2.second;
}


int main(){
  string s;
  map<string, int> counters; // store each word and an associated counter

  // read the input, keeping track of each word and how often we see it
  while(cin >> s){
    ++counters[s];
  }

  // sort the words by frequency count
  vector<pair<string, int> > wc_pairs; // word-count pairs
  copy(counters.begin(), counters.end(), back_inserter(wc_pairs));
  stable_sort(wc_pairs.begin(), wc_pairs.end(), comp_wc_pairs);

  // write the words and associated counts
  cout << endl;
  for(vector<pair<string, int> >::const_iterator it = wc_pairs.begin(); it != wc_pairs.end(); ++it){
    cout << it->first << "\t" << it->second << endl;
  }

  return 0;
}
