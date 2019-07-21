#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}

int main() {
  ll S;
  cin >> S;
  ll x1, x2, y1, y2;
  x1 = y2 = ceil(sqrt(S));
  ll T = x1 * y2 - S;
  if(T != 0) {
    find_divisor(T);
    x2 = divisor.back();
    y1 = T / x2;
  } else {
    x2 = y1 = 0;
  }
  cout << 0 << ' ' << 0 << ' '
       << x1 << ' ' << y1 << ' '
       << x2 << ' ' << y2 << endl;
  return 0;
}

