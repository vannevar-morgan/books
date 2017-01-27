#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


// -Gets input from the user to form a dataset of doubles.
// -Calculates the average of all numbers entered by the user.

int main(){
  vector<double> data;
  
  cout << "enter some numbers to calculate the average: " << endl;
  double n;
  while(cin >> n){
    data.push_back(n);
  }
  
  cout << "average: " << accumulate(data.begin(), data.end(), 0.0) / data.size() << endl;  
  
  
  return 0;
}
