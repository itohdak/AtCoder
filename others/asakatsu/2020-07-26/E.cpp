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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int a, b; cin >> a >> b; a--; b--;
  int m; cin >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  auto bfs = [&]() {
    queue<int> q;
    vector<bool> vis(n);
    vector<int> dist(n, inf);
    vector<ll> cnt(n);
    q.push(a);
    cnt[a] = 1;
    dist[a] = 0;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      if(vis[cur]) continue;
      vis[cur] = true;
      if(cur == b) continue;
      for(int ne: G[cur]) {
        if(!vis[ne]) {
          if(dist[ne] > dist[cur]+1) {
            dist[ne] = dist[cur]+1;
            cnt[ne] = 0;
            (cnt[ne] += cnt[cur]) %= mod;
          } else if(dist[ne] == dist[cur]+1) {
            (cnt[ne] += cnt[cur]) %= mod;
          }
          q.push(ne);
        }
      }
    }
    return cnt[b];
  };
  cout << bfs() << "\n";
  return 0;
}
