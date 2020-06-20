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
const ll mod = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  vector<vector<ll>> dp(C+1, vector<ll>(D+1));
  dp[A][B] = 1;
  REP(i, A, C+1) {
    REP(j, B, D+1) {
      if(i > A) (dp[i][j] += dp[i-1][j] * j) %= mod;
      if(j > B) (dp[i][j] += dp[i][j-1] * i) %= mod;
      if(i > A && j > B) (dp[i][j] += mod - (dp[i-1][j-1] * (i-1) * (j-1)) % mod) %= mod;
    }
  }
  cout << dp[C][D] << endl;
  return 0;
}
