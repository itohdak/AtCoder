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
  int X, Y, N;
  cin >> X >> Y >> N;
  vector<int> T(N), H(N);
  rep(i, N) cin >> T[i] >> H[i];
  vector<vector<vector<ll>>>
    dp(N+1, vector<vector<ll>>(X+1, vector<ll>(Y+1, 0)));
  rep(i, N) {
    rep(j, X+1) {
      rep(k, Y+1) {
        dp[i+1][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
        if(j+k < T[i]) continue;
        if(T[i]-1 <= k) {
          if(j-1 < 0) continue;
          dp[i+1][j-1][k-(T[i]-1)] = max(dp[i][j][k]+H[i],
                                         dp[i+1][j-1][k-(T[i]-1)]);
        } else {
          dp[i+1][j-(T[i]-k)][0] = max(dp[i][j][k]+H[i],
                                       dp[i+1][j-(T[i]-k)][0]);
        }
      }
    }
  }

  ll mx = 0;
  rep(j, X+1) rep(k, Y+1) {
    mx = max(dp[N][j][k], mx);
  }
  cout << mx << endl;
  return 0;
}
