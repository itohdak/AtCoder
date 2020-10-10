#include "header.hpp"

struct edge {
  int to;
  ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

vector<vector<edge>> G;
vector<ll> D;
void dfs(int tmp, int par, ll cost) {
  if(par != -1) {
    D[tmp] = D[par] + cost;
  }
  for(auto ne: G[tmp])
    if(ne.to != par)
      dfs(ne.to, tmp, ne.cost);
}

int main() {
  int N;
  cin >> N;
  G = vector<vector<edge> >(N);
  D = vector<ll>(N);
  rep(i, N-1) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back(edge(b, c));
    G[b].push_back(edge(a, c));
  }
  int s;
  cin >> s;
  s--;

  dfs(s, -1, 0);

  rep(i, N) cout << i << ": " << D[i] << endl;
  return 0;
}

