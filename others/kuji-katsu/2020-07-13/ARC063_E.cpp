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
  int k; cin >> k;
  vector<int> col(n, inf);
  int root = -1;
  rep(i, k) {
    int v, p;
    cin >> v >> p;
    v--;
    col[v] = p;
    root = v;
  }
  int root_parity = col[root]%2;
  bool ok = true;
  auto dfs = [&](auto dfs, int cur, int par, int depth) -> void {
    if(col[cur] != inf) {
      if(((depth%2)^(col[cur]%2)) != root_parity) ok = false;
    }
    for(int ne: G[cur]) if(ne != par) dfs(dfs, ne, cur, depth+1);
  };
  dfs(dfs, root, -1, 0);
  vector<pair<int, int>> range(n);
  bool ok2 = true;
  auto dfs2 = [&](auto dfs2, int cur, int par) -> pair<int, int> {
    if(col[cur] != inf) range[cur].first = range[cur].second = col[cur];
    else {
      range[cur].first = -inf;
      range[cur].second = inf;
    }
    for(int ne: G[cur]) {
      if(ne != par) {
        pair<int, int> ret = dfs2(dfs2, ne, cur);;
        range[cur].first = max(range[cur].first, ret.first);
        range[cur].second = min(range[cur].second, ret.second);
      }
    }
    if(col[cur] != inf) {
      if(col[cur] < range[cur].first || range[cur].second < col[cur]) ok2 = false;
    } else {
      if(range[cur].first > range[cur].second) ok2 = false;
    }
    if(range[cur].first == -inf) {
      return range[cur];
    } else {
      return {range[cur].first-1, range[cur].second+1};
    }
  };
  dfs2(dfs2, root, -1);
  auto dfs3 = [&](auto dfs3, int cur, int par) -> void {
    for(int ne: G[cur]) {
      if(ne != par) {
        if(col[ne] == inf) {
          if(range[ne].first <= col[cur]-1 && col[cur]-1 <= range[ne].second) {
            col[ne] = col[cur]-1;
          } else {
            col[ne] = col[cur]+1;
          }
        }
        dfs3(dfs3, ne, cur);
      }
    }
  };
  if(ok) {
    if(ok2) {
      dfs3(dfs3, root, -1);
      cout << "Yes" << "\n";
      rep(i, n) cout << col[i] << "\n";
    } else {
      cout << "No" << "\n";
    }
  } else {
    cout << "No" << "\n";
  }
  return 0;
}
