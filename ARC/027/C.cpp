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
  int x, y, n; cin >> x >> y >> n;
  vector<ll> T(n), H(n);
  rep(i, n) cin >> T[i] >> H[i];
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(x+1, vector<ll>(y+1)));
  rep(i, n) {
    rep(j, x+1) {
      rep(k, y+1) {
        dp[i+1][j][k] = max(dp[i][j][k], dp[i+1][j][k]); // 買わない
        if(j == 0) continue;
        if(j+k < T[i]) continue;
        if(k > T[i]-1) { // スペシャルは極力使わない
          dp[i+1][j-1][k-(T[i]-1)] = max(dp[i][j][k]+H[i],
                                         dp[i+1][j-1][k-(T[i]-1)]);
        } else { // 仕方なくスペシャルを複数枚使う
          dp[i+1][j-(T[i]-k)][0] = max(dp[i][j][k]+H[i], dp[i+1][j-(T[i]-k)][0]);
        }
      }
    }
  }
  ll mx = 0;
  rep(i, x+1) rep(j, y+1) mx = max(dp[n][i][j], mx);
  cout << mx << "\n";
  return 0;
}
