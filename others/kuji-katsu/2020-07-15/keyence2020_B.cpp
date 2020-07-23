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
  int n; cin >> n;
  vector<pair<ll, ll>> R(n);
  rep(i, n) {
    ll x, l; cin >> x >> l;
    R[i].first = x-l;
    R[i].second = x+l;
  }
  sort(all(R));
  vector<int> dp(n);
  dp[0] = 1;
  rep(i, n) {
    int ne = lower_bound(all(R), make_pair(R[i].second, 0LL)) - begin(R);
    dp[ne] = max(dp[i]+1, dp[ne]);
    dp[i+1] = max(dp[i], dp[i+1]);
  }
  cout << dp[n-1] << "\n";
  return 0;
}
