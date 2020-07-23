#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, t; cin >> n >> t;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  vector<vector<ll>> dp(n+1, vector<ll>(t+1));
  rep(i, n) {
    rep(j, t) {
      if(j+A[i]<=t) dp[i+1][j+A[i]] = max(dp[i][j]+B[i], dp[i+1][j+A[i]]);
      else dp[i+1][t] = max(dp[i][j]+B[i], dp[i+1][t]);
    }
  }
  ll ans = 0;
  rep(i, n+1) rep(j, t+1) ans = max(dp[i][j], ans);
  // rep(i, n) ans = max(dp[i+1][t], ans);
  // rep(i, t+1) ans = max(dp[n][i], ans);
  cout << ans << "\n";
  return 0;
}
