#include <iostream>
#include <cstdlib>
#include "nrand.h"
#include <cmath>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <numeric>

using namespace std;

int main(){
  //
  // Test the nrand function for values greater than RAND_MAX = 32767
  //
  vector<int> data;
  srand(time(0) ^ getpid());
  int n = 1000001;
  for(int i = 0; i < 50000; ++i){
    data.push_back(nrand(n));
    cout << data.back() << endl;
  }
  // Calculate and display the mean.  (law of large numbers, if our randomness is good mean should be near the middle of the range (although this doesn't prove good randomness))
  cerr << "mean:\t" << accumulate(data.begin(), data.end(), 0.0) / data.size() << endl;
  return 0;
}
