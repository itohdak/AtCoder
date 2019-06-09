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
  vector<ll> A(N);
  ll sum = 0;
  ll minAbs = 1000000005;
  ll nMinus = 0;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    sum += abs(A[i]);
    minAbs = min(minAbs, abs(A[i]));
    if(A[i] < 0)
      nMinus++;
  }
  if(nMinus % 2 == 1) {
    cout << sum - 2 * minAbs << endl;
  } else {
    cout << sum << endl;
  }
  return 0;
}

