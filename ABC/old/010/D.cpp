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
  int n, g, e;
  cin >> n >> g >> e;
  vector<int> P(g);
  vector<multiset<int>> G(n+1);
  rep(i, g) {
    cin >> P[i];
    G[P[i]].insert(n);
  }
  rep(i, e) {
    int a, b;
    cin >> a >> b;
    G[a].insert(b);
    G[b].insert(a);
  }
  bool found = false;
  vector<int> path;
  vector<bool> vis(n+1);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(cur == n) {
      path.push_back(n);
      found = true;
    }
    if(found) return;
    if(vis[cur]) return;
    vis[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        if(found) return;
      }
    }
    path.pop_back();
  };
  while(1) {
    vis = vector<bool>(n+1);
    found = false;
    dfs(dfs, 0, -1);
    if(!found) break;
    int np = path.size();
    for(int i=1; i<np; i++) {
      G[path[i-1]].erase(G[path[i-1]].find(path[i]));
      G[path[i]].insert(path[i-1]);
    }
    path.clear();
  }
  cout << G[n].size() << "\n";
  return 0;
}
