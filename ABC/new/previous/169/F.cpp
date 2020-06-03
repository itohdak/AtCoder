#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 998244353;

ll binary_pow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) {
      ans *= tmp;
      ans %= mod;
    }
    N /= 2;
    tmp *= tmp;
    tmp %= mod;
  }
  return ans;
}
ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  int S;
  cin >> N >> S;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int mx = S+1;
  vector<vector<ll>> dp(N+1, vector<ll>(mx));
  dp[0][0] = binary_pow(2, N);
  ll ans = 0;
  rep(i, N) {
    if(S-A[i]>=0) {
      (ans += dp[i][S-A[i]] * modinv(2)) %= mod;
    }
    rep(j, mx) {
      (dp[i+1][j] += dp[i][j]) %= mod;
      if(j+A[i] < mx) (dp[i+1][j+A[i]] += dp[i][j] * modinv(2)) %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
