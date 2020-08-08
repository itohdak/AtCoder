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
  int n; cin >> n;
  vector<ll> R(n); rep(i, n) cin >> R[i];
  vector<vector<int>> dp(n, vector<int>(2));
  dp[0][0] = dp[0][1] = 1;
  rep(i, n) {
    REP(j, i+1, n) {
      if(R[j] > R[i]) dp[j][0] = max(dp[i][1]+1, dp[j][0]);
      if(R[j] < R[i]) dp[j][1] = max(dp[i][0]+1, dp[j][1]);
    }
  }
  int mx = 0;
  rep(i, n) mx = max({dp[i][0], dp[i][1], mx});
  cout << (mx < 3 ? 0 : mx) << "\n";
  return 0;
}
