#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct Edge{
  int to, cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};
typedef vector<vector<Edge> > AdjList;
AdjList graph;

vector<ll> dist;
vector<int> par;
bool bellman_ford(int n, int s){ // n: number of edges, s: source
  dist = vector<ll>(n, longinf);
  par = vector<int>(n);
  par[s] = -1;
  dist[s] = 0;
  rep(i, n) {
    rep(v, n) {
      for(auto e: graph[v]) {
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

set<pair<int, int> > s;
vector<int> buildPath(int t) {
  vector<int> path;
  for(int u=t; u>=0; u=par[u]) {
    path.push_back(u);
    if(s.count(make_pair(min(u, par[u]), max(u, par[u]))))
      s.erase(make_pair(min(u, par[u]), max(u, par[u])));
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  int N, M;
  cin >> N >> M;
  graph = AdjList(N, vector<Edge>());
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    s.insert(make_pair(min(a, b), max(a, b)));
    graph[a].push_back(Edge(b, c));
    graph[b].push_back(Edge(a, c));
  }
  rep(i, N) {
    bellman_ford(N, i);
    rep(j, N)
      if(i != j)
        buildPath(j);
  }
  cout << s.size() << endl;
  return 0;
}

