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
  vector<ll> X, X_;
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    X.push_back(in);
    X_.push_back(in);
  }
  sort(X.begin(), X.end());
  ll ret1 = X[N/2-1];
  ll ret2 = X[N/2];
  for(int i=0; i<N; i++){
    if(X_[i] < ret2)
      cout << ret2 << endl;
    else
      cout << ret1 << endl;
  }
  return 0;
}

