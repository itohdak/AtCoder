#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
  vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(r+1, vector<ll>(c+1)));
  rep(i, r) {
    rep(j, c) {
      rep(k, 4) {
        chmax(dp[k][i][j+1], dp[k][i][j]);
        if(k != 3) chmax(dp[k+1][i][j+1], dp[k][i][j]+V[i][j]);
      }
    }
    rep(j, c+1) {
      rep(k, 4) {
        chmax(dp[0][i+1][j], dp[k][i][j]);
        if(i != r-1 && j != 0) chmax(dp[1][i+1][j], dp[k][i][j]+V[i+1][j-1]);
      }
    }
  }
  ll ans = 0;
  rep(k, 4) chmax(ans, dp[k][r][c]);
  cout << ans << endk;
  return 0;
}
