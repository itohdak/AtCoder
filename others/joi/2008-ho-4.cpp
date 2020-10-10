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
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> K(n);
  vector<vector<int>> S(n), P(n);
  rep(i, n) {
    cin >> K[i];
    S[i] = vector<int>(K[i]);
    P[i] = vector<int>(K[i]);
    rep(j, K[i]) cin >> P[i][j] >> S[i][j];
  }
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(10, vector<ll>(m+1, longinf)));
  rep(k, K[0]) dp[0][k][0] = 0;
  rep(i, n-1) {
    rep(k1, K[i]) {
      rep(j, m+1) {
        if(i+1 < n) {
          rep(k2, K[i+1]) {
            chmin(dp[i+1][k2][j],
                  dp[i][k1][j] + (S[i][k1]+S[i+1][k2])*abs(P[i][k1]-P[i+1][k2]));
          }
        }
        if(j+1 > m) continue;
        if(i+2 < n) {
          rep(k2, K[i+2]) {
            chmin(dp[i+2][k2][j+1],
                  dp[i][k1][j] + (S[i][k1]+S[i+2][k2])*abs(P[i][k1]-P[i+2][k2]));
          }
        }
      }
    }
  }
  ll ans = longinf;
  rep(k, K[n-1]) chmin(ans, *min_element(all(dp[n-1][k])));
  cout << ans << endk;
  return 0;
}
