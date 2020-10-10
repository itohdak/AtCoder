#include "header.hpp"

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};
vector<vector<edge>> G;

vector<ll> dist;
vector<int> par;
bool bellman_ford(int n, int s) {
  // n: number of vertices, s: source
  dist = vector<ll>(n, longinf);
  par = vector<int>(n);
  dist[s] = 0;
  rep(i, n) {
    rep(v, n) {
      for(auto e: G[v]) {
        if(dist[v] != longinf && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          par[e.to] = v;
          if(i == n-1) return true;
        }
      }
    }
  }
  return false;
}

vector<int> buildPath(int t) {
  vector<int> path;
  for(int u=t; u>=0; u=par[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}

void print_cost(int n, int s) {
  cout << endl;
  for(int i=0; i<n; i++) {
    if(i != s) cout << "Cost from " << s << " to " << i << ": " << dist[i] << endl;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  G = vector<vector<edge>>(n);
  par = vector<int>(n, -1);

  rep(i, m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    G[from].push_back(edge(to, cost));
  }

  rep(s, n) {
    bellman_ford(n, s);
    print_cost(n, s);
  }
  return 0;
}
