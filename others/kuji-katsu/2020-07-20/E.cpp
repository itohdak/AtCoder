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
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(3*n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    rep(j, 3) {
      G[3*u+j].push_back({3*v+(j+1)%3, 1});
    }
  }
  int s, t; cin >> s >> t;
  s--; t--;
  dijkstra(3*s, 3*n, G);
  cout << (d[3*t]==longinf ? -1 : d[3*t]/3) << "\n";
  return 0;
}
