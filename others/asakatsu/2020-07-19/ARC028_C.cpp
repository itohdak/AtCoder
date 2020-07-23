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
  vector<vector<int>> G(n);
  rep(i, n) {
    if(i) {
      int p; cin >> p;
      G[i].push_back(p);
      G[p].push_back(i);
    }
  }
  vector<vector<int>> child(n);
  vector<int> sum(n);
  auto dfs = [&](auto dfs, int cur, int par) -> int {
    for(int ne: G[cur]) {
      if(ne != par) {
        int ret = dfs(dfs, ne, cur);
        child[cur].push_back(ret);
        sum[cur] += ret;
      }
    }
    return sum[cur]+1;
  };
  dfs(dfs, 0, -1);
  vector<int> ans(n);
  auto dfs2 = [&](auto dfs2, int cur, int par, int val) -> void {
    if(child[cur].empty()) ans[cur] = val;
    else ans[cur] = max(*max_element(all(child[cur])), val);
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs2(dfs2, ne, cur, val+sum[cur]-sum[ne]);
      }
    }
  };
  dfs2(dfs2, 0, -1, 0);
  rep(i, n) cout << ans[i] << "\n";
  return 0;
}
