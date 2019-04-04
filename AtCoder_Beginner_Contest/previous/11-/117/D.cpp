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
  ll K;
  cin >> N >> K;
  vector<int> digitK(40, 0);
  ll tmpK = K+1;
  for(int d=0; d<40; d++) {
    digitK[d] = tmpK % 2;
    tmpK /= 2;
    if(tmpK == 0)
      break;
  }
  vector<int> digits(40, 0);
  vector<ll> A(N);
  for(int i=0; i<N; i++) {
    cin >> A[i];
    ll tmpA = A[i];
    for(int d=0; d<40; d++) {
      digits[d] += tmpA % 2;
      tmpA /= 2;
      if(tmpA == 0)
break;
    }
  }
  ll tmp = (K+1) & ~(1); // 0ビット目に0
  ll ans = 0;
  for(int d=0; d<40; d++) {
    if(digitK[d] == 1 && tmp <= K) {
      ll fx = 0;
      for(int i=0; i<N; i++)
fx += tmp ^ A[i];
      ans = max(ans, fx);
    }
    if(digits[d] <= N - digits[d])
      tmp |= (1LL << d); // dビット目に1
    tmp &= ~(1LL << (d+1)); // d+1ビット目に0
  }
  cout << ans << endl;
  return 0;
}

