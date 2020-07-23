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
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> path;
  bool reached = false;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(cur == n-1) {
      path.push_back(n-1);
      reached = true;
      return;
    }
    if(reached) return;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
      if(reached) return;
    }
    path.pop_back();
  };
  dfs(dfs, 0, -1);
  int l = 0, r = path.size()-1;
  vector<int> col(n, -1);
  while(l <= r) {
    col[path[l]] = 0;
    l++;
    if(l > r) break;
    col[path[r]] = 1;
    r--;
  }
  auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
    if(par != -1 && col[cur] == -1) col[cur] = col[par];
    for(int ne: G[cur]) {
      if(ne != par) dfs2(dfs2, ne, cur);
    }
  };
  dfs2(dfs2, path[l], -1);
  int score = accumulate(all(col), 0);
  cout << (score >= n-score ? "Snuke" : "Fennec") << "\n";
  return 0;
}
