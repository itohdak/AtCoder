#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, ma, mb; cin >> n >> ma >> mb;
  vector<int> A(n), B(n), C(n);
  rep(i, n) cin >> A[i] >> B[i]>> C[i];
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(405, vector<ll>(405, longinf)));
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, 405) rep(k, 405) {
      dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
      if(j+A[i]<405 && k+B[i]<405) {
        dp[i+1][j+A[i]][k+B[i]] = min(dp[i][j][k]+C[i], dp[i+1][j+A[i]][k+B[i]]);
      }
    }
  }
  ll ans = longinf;
  rep(j, 405) rep(k, 405) {
    if(j < 1 || k < 1) continue;
    if(1LL*j*mb == 1LL*k*ma) {
      ans = min(dp[n][j][k], ans);
    }
  }
  cout << (ans==longinf ? -1 : ans) << endk;
  return 0;
}
