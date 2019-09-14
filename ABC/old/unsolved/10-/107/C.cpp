#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  vector<ll> X(N);
  for(int i=0; i<N; i++) {
    cin >> X[i];
  }
  ll m = 1e+18;
  for(int i=0; i<N-K+1; i++) {
    if(X[i+K-1] * X[i] < 0) {
      if(m > X[i+K-1] - X[i] + min(X[i+K-1], abs(X[i]))) {
	m = X[i+K-1] - X[i] + min(X[i+K-1], abs(X[i]));
      }
    } else {
      if(m > X[i+K-1] - X[i] + min(abs(X[i+K-1]), abs(X[i]))) {
	m = X[i+K-1] - X[i] + min(abs(X[i+K-1]), abs(X[i]));
      }
    }
  }

  cout << m << endl;
  return 0;
}

