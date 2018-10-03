#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int D;
  ll G;
  cin >> D >> G;
  vector<int> P(D);
  vector<ll> C(D);
  for(int i=0; i<D; i++)
    cin >> P[i] >> C[i];
  
  return 0;
}

