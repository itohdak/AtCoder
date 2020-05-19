#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<ll> C(N), D(N);
  rep(i, N) cin >> C[i];
  rep(i, N) cin >> D[i];
  vector<vector<ll>> dp(N+1, vector<ll>(N+1, longinf));
  dp[0][0] = 0;
  rep(i, N) {
    rep(j, N+1) {
      if(S[i] == '(') {
        dp[i+1][j] = min(dp[i][j]+D[i], dp[i+1][j]);
        if(j-1>=0) dp[i+1][j-1] = min(dp[i][j]+C[i], dp[i+1][j-1]);
        dp[i+1][j+1] = min(dp[i][j], dp[i+1][j+1]);
      } else {
        dp[i+1][j] = min(dp[i][j]+D[i], dp[i+1][j]);
        dp[i+1][j+1] = min(dp[i][j]+C[i], dp[i+1][j+1]);
        if(j-1>=0) dp[i+1][j-1] = min(dp[i][j], dp[i+1][j-1]);
      }
    }
  }
  cout << dp[N][0] << endl;
  return 0;
}
