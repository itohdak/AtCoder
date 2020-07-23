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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<int> C(n), R(n);
  rep(i, n) cin >> C[i] >> R[i];
  vector<vector<int>> G(n);
  rep(i, k) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<vector<edge>> G2(n);
  auto bfs = [&](int i) {
    queue<int> q;
    q.push(i);
    vector<bool> vis(n);
    vector<int> d(n, inf);
    d[i] = 0;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      if(vis[cur]) continue;
      vis[cur] = true;
      if(cur != i) G2[i].emplace_back(cur, C[i]);
      vis[cur] = true;
      for(int ne: G[cur]) {
        if(d[ne] > d[cur]+1 && d[cur]+1 <= R[i]) {
          d[ne] = d[cur]+1;
          q.push(ne);
        }
      }
    }
  };
  rep(i, n) bfs(i);
  dijkstra(0, n, G2);
  cout << d[n-1] << "\n";
  return 0;
}
