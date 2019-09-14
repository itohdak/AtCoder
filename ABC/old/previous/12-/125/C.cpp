#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  vector<ll> gcdLeft(N), gcdRight(N);
  gcdLeft[0] = A[0];
  for(int i=1; i<N; i++)
    gcdLeft[i] = gcd(gcdLeft[i-1], A[i]);
  gcdRight[N-1] = A[N-1];
  for(int i=N-2; i>=0; i--)
    gcdRight[i] = gcd(gcdRight[i+1], A[i]);
  ll ans = 1;
  ans = max(gcdRight[1], max(gcdLeft[N-2], ans));
  for(int i=1; i<N-1; i++) {
    ans = max(gcd(gcdLeft[i-1], gcdRight[i+1]), ans);
  }
  cout << ans << endl;
  return 0;
}

