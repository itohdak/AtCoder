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
  vector<int> ans(n);
  auto dfs = [&](auto dfs, int cur, int par) -> int {
    int sum = 0;
    int mx = 0;
    for(int ne: G[cur]) {
      if(ne != par) {
        int ret = dfs(dfs, ne, cur);
        mx = max(ret, mx);
        child[cur].push_back(ret);
        sum += ret;
      }
    }
    ans[cur] = max(mx, n-sum-1);
    return sum+1;
  };
  dfs(dfs, 0, -1);
  rep(i, n) cout << ans[i] << "\n";
  return 0;
}
