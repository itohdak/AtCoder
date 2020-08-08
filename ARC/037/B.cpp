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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int v, w; cin >> v >> w;
    v--; w--;
    G[v].push_back(w);
    G[w].push_back(v);
  }
  vector<bool> vis(n);
  vector<bool> fin(n);
  bool loop = false;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(vis[cur] && !fin[cur]) {
      loop = true;
      return;
    }
    if(vis[cur]) return;
    vis[cur] = true;
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
    fin[cur] = true;
  };
  int ans = 0;
  rep(i, n) {
    if(!vis[i]) {
      loop = false;
      dfs(dfs, i, -1);
      if(!loop) ans++;
    }
  }
  cout << ans << endk;
  return 0;
}
