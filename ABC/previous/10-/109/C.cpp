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
  int N;  ll X;
  cin >> N >> X;
  vector<ll> x(N+1);
  x[0] = X;
  for(int i=0; i<N; i++)
    cin >> x[i+1];
  sort(x.begin(), x.end());
  vector<ll> y(N);
  ll ans;
  for(int i=0; i<N; i++) {
    y[i] = x[i+1] - x[i];
    if(i == 0)
      ans = y[i];
    else
      ans = gcd(ans, y[i]);
  }
  cout << ans << endl;
  return 0;
}

