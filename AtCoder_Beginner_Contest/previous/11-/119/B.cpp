#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  double sum = 0;
  for(int i=0; i<N; i++) {
    double x;
    string u;
    cin >> x >> u;
    if(u == "JPY")
      sum += x;
    else
      sum += 380000 * x;
  }
  cout << sum << endl;
  return 0;
}

