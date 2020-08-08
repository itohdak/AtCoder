#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<vector<int>> G;
vector<int> Tpl;

/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}
// rep(i, N) dfs(i);
// reverse(all(Tpl));


/* topological sort with loop detection */
vector<bool> seen, finished;
bool dfs2(int cur, int par) {
  if(seen[cur] && !finished[cur]) return true;
  if(seen[cur] || finished[cur]) return false;
  seen[cur] = true;
  bool ret = false;
  for(int ne: G[cur]) {
    if(ne == par) continue;
    ret |= dfs2(ne, cur);
  }
  finished[cur] = true;
  Tpl.push_back(cur);
  return ret;
};
// bool ret = false;
// rep(i, n) ret |= dfs2(i, -1);
// if(ret) {
//   // loop
// } else {
//   reverse(all(Tpl));
// }
