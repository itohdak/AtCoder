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
  int n, m; cin >> n >> m;
  vector<ll> cost(m);
  vector<ll> val(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    cost[i] = a;
    rep(j, b) {
      int c;
      cin >> c;
      c--;
      val[i] += 1<<c;
    }
  }
  vector<vector<ll>> dp(m+1, vector<ll>(1<<n, longinf));
  dp[0][0] = 0;
  rep(i, m) rep(j, 1<<n) {
    dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
    dp[i+1][j|val[i]] = min(dp[i][j]+cost[i], dp[i+1][j|val[i]]);
  }
  cout << (dp[m][(1<<n)-1]==longinf ? -1 : dp[m][(1<<n)-1]) << "\n";
  return 0;
}
