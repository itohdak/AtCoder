#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
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
  graph = AdjList(n);
  par = vector<int>(n, -1);

  rep(i, m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back(Edge(to, cost));
  }

  rep(s, n) {
    bellman_ford(n, s);
    print_cost(n, s);
  }
  return 0;
}
