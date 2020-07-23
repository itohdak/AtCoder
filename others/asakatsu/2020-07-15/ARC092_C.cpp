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
  vector<pair<int, int>> R(n), B(n);
  rep(i, n) cin >> R[i].first >> R[i].second;
  rep(i, n) cin >> B[i].first >> B[i].second;
  vector<set<int>> G(2*n+2);
  rep(i, n) G[2*n].insert(i); // 始点
  rep(j, n) G[j+n].insert(2*n+1); // 終点
  rep(i, n) rep(j, n) {
    if(R[i].first < B[j].first && R[i].second < B[j].second) {
      G[i].insert(j+n);
    }
  }
  vector<int> path;
  bool flag = false;
  vector<bool> vis;
  auto dfs = [&](auto dfs, int cur, int par) {
    if(flag) return;
    if(vis[cur]) return;
    if(cur == 2*n+1) {
      path.push_back(2*n+1);
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
    vis = vector<bool>(2*n+2);
    dfs(dfs, 2*n, -1);
    if(!flag) break;
  }
  cout << G[2*n+1].size() << "\n";
  return 0;
}
