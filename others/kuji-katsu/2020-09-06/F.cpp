#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, s; cin >> n >> s;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> dp(n+1, vector<ll>(s+1));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, s+1) {
     (dp[i+1][j] += dp[i][j] * 2) %= mod;
     if(j+A[i]<=s) (dp[i+1][j+A[i]] += dp[i][j]) %= mod;
    }
  }
  cout << dp[n][s] << endk;
  return 0;
}
