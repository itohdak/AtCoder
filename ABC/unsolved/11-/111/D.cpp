#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <set>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<ll> X(N), Y(N);
  for(int i=0; i<N; i++)
    cin >> X[i] >> Y[i];
  return 0;
}

