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
  int r, c, k; cin >> r >> c >> k;
  vector<vector<ll>> V(r, vector<ll>(c));
  rep(i, k) {
    int r, c; ll v;
    cin >> r >> c >> v;
    r--; c--;
    V[r][c] = v;
  }
  vector<vector<ll>> dp(r+1, vector<ll>(c+1));
  rep(i, r) {
    vector<vector<ll>> dp2(c+1, vector<ll>(4));
    // rep(j, c) rep(k, 4) dp2[j][k] = dp[i][j+1];
    rep(j, c+1) {
      dp2[j][0] = dp[i][j];
      if(j) dp2[j][1] = dp[i][j]+V[i][j-1];
    }
    rep(j, c) {
      rep(k, 4) {
        dp2[j+1][k] = max(dp2[j][k], dp2[j+1][k]);
        if(k+1<4) dp2[j+1][k+1] = max(dp2[j][k]+V[i][j], dp2[j+1][k+1]);
      }
    }
    rep(j, c+1) {
      dp[i+1][j] = max({dp2[j][0], dp2[j][1], dp2[j][2], dp2[j][3]});
    }
  }
  cout << dp[r][c] << endk;
  return 0;
}
