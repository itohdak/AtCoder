#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll t[200000];

int main(){
  int N;  ll T;
  cin >> N >> T;
  for(int i=0; i<N; i++)
    cin >> t[i];
  ll sum = T; // last
  for(int i=0; i<N-1; i++) {
    if(t[i+1] - t[i] < T)
      sum += t[i+1] - t[i];
    else
      sum += T;
  }
  cout << sum << endl;
  return 0;
}

