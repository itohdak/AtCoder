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
  int n, m, k, s; cin >> n >> m >> k >> s;
  ll p, q; cin >> p >> q;
  vector<int> C(k);
  set<int> zombie;
  rep(i, k) {
    cin >> C[i];
    C[i]--;
    zombie.insert(C[i]);
  }
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  set<int> danger;
  auto bfs = [&]() {
    vector<int> dist(n, inf);
    queue<int> q;
    rep(i, k) {
      dist[C[i]] = 0;
      q.push(C[i]);
    }
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(int ne: G[cur]) {
        if(dist[ne] > dist[cur]+1 && dist[cur]+1 <= s) {
          dist[ne] = dist[cur]+1;
          q.push(ne);
        }
      }
    }
    rep(i, n) if(dist[i] != inf && !zombie.count(i)) danger.insert(i);
  };
  bfs();
  vector<vector<edge>> G2(n);
  rep(i, n) {
    for(int ne: G[i]) {
      if(zombie.count(ne)) continue;
      if(ne == n-1)             G2[i].push_back({ne, 0});
      else if(danger.count(ne)) G2[i].push_back({ne, q});
      else                      G2[i].push_back({ne, p});
    }
  }
  dijkstra(0, n, G2);
  cout << d[n-1] << endk;
  return 0;
}
