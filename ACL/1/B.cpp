#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

void find_divisor(ll N, vector<ll>& divisor) {
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
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b * x;
  return d;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  // k * (k+1) % (2*n) == 0
  vector<ll> div;
  find_divisor(n*2, div);
  // cout << div << endk;
  ll ans = n*2-1;
  for(ll d1: div) {
    ll d2 = n*2/d1;
    if(__gcd(d1, d2) != 1) continue;
    // d1 * x + d2 * y == 1
    ll x, y;
    extGCD(d1, d2, x, y);
    if(x == 0 || y <= 0) continue;
    // cout << d1 << ' ' << d2 << ' ' << x << ' ' << y << endk;
    // cout << d1 * x + d2 * y << endk;
    chmin(ans, -d1*x);
  }
  cout << ans << endk;
  return 0;
}
