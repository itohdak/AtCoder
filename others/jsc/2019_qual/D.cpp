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
  int N;
  cin >> N;
  vector<int> ans(N);
  vector<vector<int>> G(N);
  rep(i, N) rep(j, N) {
    if(i != j) G[i].push_back(j);
  }
  vector<int> done(N*N, -1);
  int col = 0;
  vector<int> depth(N);
  vector<bool> vis(N);
  int cnt = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> bool {
    // cout << cur << ' ' << par << endl;
    if(vis[cur]) return false;
    vis[cur] = true;
    bool updated = false;
    for(int ne: G[cur]) {
      int e = min(cur, ne)*N+max(cur, ne);
      if(ne != par && done[e]==-1) {
        updated = true;
        if(vis[ne]) {
          if(abs(depth[cur]-depth[ne])%2) {
            done[e] = col;
            cnt++;
          }
        } else {
          done[e] = col;
          cnt++;
          depth[ne] = depth[cur]+1;
          dfs(dfs, ne, cur);
        }
      }
    }
    return updated;
  };
  while(cnt < N*(N-1)/2) {
    depth = vector<int>(N);
    vis = vector<bool>(N);
    rep(i, N) if(!vis[i]) dfs(dfs, i, -1);
    col++;
  }
  rep(i, N) {
    for(int j=i+1; j<N; j++) cout << done[i*N+j]+1 << ' ';
    cout << "\n";
  }
  return 0;
}
