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
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> path;
  vector<bool> vis(n);
  ll ans = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if((int)path.size() == n-1) {
      ans++;
      return;
    }
    vis[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(!vis[ne]) dfs(dfs, ne, cur);
    }
    vis[cur] = false;
    path.pop_back();
  };
  dfs(dfs, 0, -1);
  cout << ans << "\n";
  return 0;
}
