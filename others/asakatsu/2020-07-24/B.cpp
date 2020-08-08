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
  int n, m; cin >> n >> m;
  vector<int> D(m); rep(i, m) cin >> D[i];
  map<int, int> mp; rep(i, n+1) mp[i] = i;
  vector<int> ans(n+1); rep(i, n+1) ans[i] = i;
  int cur = 0;
  rep(i, m) {
    mp[cur] = mp[D[i]];
    mp[D[i]] = 0;
    cur = D[i];
  }
  for(auto ele: mp) ans[ele.second] = ele.first;
  rep(i, n) cout << ans[i+1] << "\n";
  return 0;
}
