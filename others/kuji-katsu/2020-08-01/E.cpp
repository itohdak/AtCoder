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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, a; cin >> n >> a;
  vector<int> X(n); rep(i, n) cin >> X[i];
  int mx = 50*n;
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(mx+1)));
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, n+1) {
      rep(k, mx+1) {
        dp[i+1][j][k] += dp[i][j][k];
        if(j+1<n+1 && k+X[i]<mx+1) {
          dp[i+1][j+1][k+X[i]] += dp[i][j][k];
        }
      }
    }
  }
  ll ans = 0;
  REP(j, 1, n+1) {
    ans += dp[n][j][a*j];
  }
  cout << ans << "\n";
  return 0;
}
