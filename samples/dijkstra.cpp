#include "header.hpp"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

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
