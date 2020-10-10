#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return g * (x / g) * (y / g);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  auto count = [&](ll n) {
    int ret = 0;
    while(n % 2 == 0) {
      ret++;
      n /= 2;
    }
    return ret;
  };
  int cnt = count(A[0]);
  rep(i, n) {
    if(count(A[i]) != cnt) {
      cout << 0 << endk;
      return 0;
    }
  }
  ll l = A[0];
  rep(i, n) {
    l = lcm(A[i], l);
    if(l/2 > m) {
      cout << 0 << endk;
      return 0;
    }
  }
  cout << (m-l/2) / l + 1 << endk;
  return 0;
}
