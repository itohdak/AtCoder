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
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  set<int> st2, st1;
  auto dfs = [&](auto dfs, int cur, int par, int depth) -> void {
    if(depth == 2) {
      st2.insert(cur);
      return;
    }
    if(depth == 1) {
      st1.insert(cur);
    }
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur, depth+1);
    }
  };
  rep(i, n) {
    st1.clear();
    st2.clear();
    st1.insert(i);
    dfs(dfs, i, -1, 0);
    int cnt = 0;
    for(auto j: st2) {
      if(!st1.count(j)) cnt++;
    }
    cout << cnt << endk;
  }
  return 0;
}
