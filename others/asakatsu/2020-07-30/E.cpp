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
  vector<ll> C(n);
  map<int, vector<int>> mp;
  rep(i, n) {
    cin >> C[i];
    mp[C[i]].push_back(i);
  }
  vector<vector<ll>> dp(n+1, vector<ll>(2));
  dp[0][0] = 1;
  rep(i, n) {
    (dp[i+1][0] += dp[i][0] + dp[i][1]) %= mod;
    auto itr = lower_bound(all(mp[C[i]]), i+1);
    if(itr != mp[C[i]].end()) {
      if(*itr > i+1) (dp[*itr+1][1] += dp[i+1][0] + dp[i+1][1]) %= mod;
    }
    // cout << dp << endl;
  }
  cout << (dp[n][0]+dp[n][1])%mod << "\n";
  return 0;
}
