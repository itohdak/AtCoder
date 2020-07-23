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
  int n, m; cin >> n >> m;
  vector<int> S(n), T(m);
  rep(i, n) cin >> S[i];
  map<int, vector<int>> mp;
  rep(i, m) {
    cin >> T[i];
    mp[T[i]].push_back(i);
  }
  vector<vector<ll>> dp(n+1, vector<ll>(m+1));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, m+1) {
      (dp[i+1][j] += dp[i][j]) %= mod;
      auto itr = lower_bound(all(mp[S[i]]), j);
      if(itr != mp[S[i]].end()) (dp[i+1][*itr+1] += dp[i][j]) %= mod;
    }
    for(auto& ele: mp) {
      rep(j, ele.second.size()) {
        if(j) (dp[i+1][ele.second[j]+1] += (mod+dp[i+1][ele.second[j-1]+1]-dp[i][ele.second[j-1]+1])%mod) %= mod;
      }
    }
  }
  ll ans = 0;
  rep(i, m+1) (ans += dp[n][i]) %= mod;
  cout << ans << "\n";
  return 0;
}
