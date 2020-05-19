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
  int W, N, K;
  cin >> W >> N >> K;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  vector<vector<vector<ll>>>
    dp(N+1, vector<vector<ll>>(W+1, vector<ll>(K+1)));
  rep(i, N) {
    rep(j, W+1) {
      rep(k, K+1) {
        dp[i+1][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
        if(j+A[i]<=W && k+1<=K) {
          dp[i+1][j+A[i]][k+1] = max(dp[i][j][k]+B[i], dp[i+1][j+A[i]][k+1]);
        }
      }
    }
  }
  ll mx = 0;
  rep(j, W+1) rep(k, K+1) mx = max(dp[N][j][k], mx);
  cout << mx << endl;
  return 0;
}
