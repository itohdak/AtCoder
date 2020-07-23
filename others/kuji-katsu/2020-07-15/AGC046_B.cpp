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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<vector<ll>> dp(c+1, vector<ll>(d+1));
  dp[a][b] = 1;
  for(ll i=a; i<=c; i++) {
    for(ll j=b; j<=d; j++) {
      if(i==a&&j==b) continue;
      if(i!=a) (dp[i][j] += dp[i-1][j]*j) %= mod;
      if(j!=b) (dp[i][j] += dp[i][j-1]*i) %= mod;
      if(i!=a&&j!=b) (dp[i][j] += mod - dp[i-1][j-1]*(i-1)%mod*(j-1)%mod) %= mod;
    }
  }
  cout << dp[c][d] << "\n";
  return 0;
}
