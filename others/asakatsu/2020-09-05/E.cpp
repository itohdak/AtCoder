#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

vector<vector<int>> G;
vector<int> Tpl;
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
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> A(n, vector<int>(n-1));
  rep(i, n) rep(j, n-1) {
    cin >> A[i][j];
    A[i][j]--;
  }
  G = vector<vector<int>>(n*(n-1)/2);
  seen = vector<bool>(n*(n-1)/2);
  finished = vector<bool>(n*(n-1)/2);
  map<pair<int, int>, int> id;
  vector<pair<int, int>> P(n*(n-1)/2);
  {
    int tmp = 0;
    rep(i, n) REP(j, i+1, n) {
      id[{i, j}] = tmp;
      P[tmp] = {i, j};
      tmp++;
    }
  }
  auto getId = [&](int i, int j) {
    pair<int, int> p = {min(i, j), max(i, j)};
    assert(id.count(p));
    return id[p];
  };
  auto getPair = [&](int id) {
    return P[id];
  };
  rep(i, n) rep(j, n-2) {
    G[getId(i, A[i][j])].push_back(getId(i, A[i][j+1]));
  }
  bool ret = false;
  rep(i, n*(n-1)/2) ret |= dfs2(i, -1);
  if(ret) { // loop
    cout << -1 << endk;
    return 0;
  } else {
    reverse(all(Tpl));
    int ans = 0;
    vector<bool> vis(n*(n-1)/2);
    vector<int> depth(n*(n-1)/2);
    auto dfs = [&](auto dfs, int cur, int dep) -> void {
      if(vis[cur]) {
        chmax(ans, dep+depth[cur]);
        return;
      }
      vis[cur] = true;
      for(auto ne: G[cur]) {
        dfs(dfs, ne, dep+1);
        chmax(depth[cur], depth[ne]);
      }
      depth[cur]++;
      chmax(ans, dep+depth[cur]);
    };
    for(int i: Tpl) dfs(dfs, i, 0);
    cout << ans << endk;
  }
  return 0;
}
