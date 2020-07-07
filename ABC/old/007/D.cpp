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
  ll a, b; cin >> a >> b;
  auto calc = [&](ll n) -> ll {
    vector<int> D;
    ll orig = n;
    while(n > 0) {
      D.push_back(n%10);
      n /= 10;
    }
    reverse(all(D));
    int d = D.size();
    vector<vector<ll>> dp(d+1, vector<ll>(2));
    dp[0][0] = 1;
    rep(i, d) {
      // 0 1 2 3 (4) 5 6 7 8 (9)
      if(D[i] == 9) {
        dp[i+1][0] = 0;
        dp[i+1][1] += dp[i][0]*8 + dp[i][1]*8;
      } else if(D[i] > 4) {
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][0]*(D[i]-1) + dp[i][1]*8;
      } else if(D[i] == 4) {
        dp[i+1][0] = 0;
        dp[i+1][1] += dp[i][0]*4 + dp[i][1]*8;
      } else {
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][0]*D[i] + dp[i][1]*8;
      }
    }
    return orig+1 - (dp[d][0] + dp[d][1]);
  };
  cout << calc(b) - calc(a-1) << "\n";
  return 0;
}
