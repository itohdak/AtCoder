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
const ll mod = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, s; cin >> n >> s;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(s+1, vector<ll>(3)));
  dp[0][0][0] = 1;
  rep(i, n) rep(j, s+1) {
    (dp[i+1][j][0] += dp[i][j][0]) %= mod;
    (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
    (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
    if(j+A[i]<=s) {
      (dp[i+1][j+A[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
      (dp[i+1][j+A[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
    }
  }
  cout << dp[n][s][2] << "\n";
  return 0;
}
