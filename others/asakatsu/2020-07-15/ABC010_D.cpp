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
  int n, g, e; cin >> n >> g >> e;
  vector<int> P(g);
  vector<set<int>> G(n+1);
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
  vector<int> path;
  bool flag = false;
  vector<bool> vis(n+1);
  auto dfs = [&](auto dfs, int cur, int par) {
    if(flag) return;
    if(vis[cur]) return;
    if(cur == n) {
      path.push_back(n);
      int s = path.size();
      rep(i, s) if(i) {
        G[path[i-1]].erase(path[i]);
        G[path[i]].insert(path[i-1]);
      }
      flag = true;
      return;
    }
    vis[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        if(flag) return;
      }
    }
    path.pop_back();
  };
  while(1) {
    path.clear();
    flag = false;
    vis = vector<bool>(n+1);
    dfs(dfs, 0, -1);
    if(!flag) break;
  }
  cout << G[n].size() << "\n";
  return 0;
}
