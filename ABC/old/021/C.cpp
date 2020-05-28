#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  int a, b;
  cin >> N >> a >> b >> M;
  --a, --b;
  vector<vector<int>> G(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  auto bfs = [&](int a, int b) {
    queue<int> q;
    q.push(a);
    vector<bool> vis(N);
    vector<int> dist(N);
    vector<int> cnt(N);
    vis[a] = true;
    cnt[a] = 1;
    dist[a] = 0;
    while(!q.empty()) {
      int tmp = q.front();
      q.pop();
      if(tmp == b) break;
      for(int ne: G[tmp]) {
        if(vis[ne] && dist[ne] < dist[tmp]+1) continue;
        else if(vis[ne]) (cnt[ne] += cnt[tmp]) %= mod;
        else {
          vis[ne] = true;
          dist[ne] = dist[tmp]+1;
          (cnt[ne] += cnt[tmp]) %= mod;
          q.push(ne);
        }
      }
    }
    // cout << cnt << endl;
    return cnt[b];
  };
  cout << bfs(a, b) << endl;
  return 0;
}
